
#include "../include/CRat.hpp"

CRat_t::CRat_t ()
{
  m_array_p = 0;
  m_array_q = 0;
  m_array_size = 0;
}

CRat_t::CRat_t (int array_size)
{
  if (array_size > 0)
    {
      m_array_size = array_size;
      m_array_p = new int [m_array_size];
      m_array_q = new int [m_array_size];
      memset (m_array_p, 0, m_array_size * sizeof (int));
      memset (m_array_q, 0, m_array_size * sizeof (int));
    }
  else
    {
      m_array_p = 0;
      m_array_q = 0;
      m_array_size = 0;
    }
}

CRat_t::CRat_t (int *array_p, int *array_q, int array_size)
{
  if (array_size > 0 && array_p && array_q)
    {
      m_array_size = array_size;
      m_array_p = new int [m_array_size];
      m_array_q = new int [m_array_size];
      memcpy (m_array_p, array_p, m_array_size * sizeof (int));
      memcpy (m_array_q, array_q, m_array_size * sizeof (int));
    }
  else
    {
      m_array_p = 0;
      m_array_q = 0;
      m_array_size = 0;
    }
}

CRat_t::~CRat_t ()
{
  if (m_array_p)
    delete [] m_array_p;
  if (m_array_q)
    delete [] m_array_q;
}

int *CRat_t::get_array_p ()
{
  return m_array_p;
}

int *CRat_t::get_array_q ()
{
  return m_array_q;
}

int CRat_t::get_array_size ()
{
  return m_array_size;
}

void CRat_t::set_array_p (int *array_p)
{
  if (m_array_p)
    delete [] m_array_p;
  m_array_p = array_p;
}

void CRat_t::set_array_q (int *array_q)
{
  if (m_array_q)
    delete [] m_array_q;
  m_array_q = array_q;
}

void CRat_t::set_array_size (int array_size)
{
  m_array_size = array_size;
}

void CRat_t::init_vector ()
{
  for (int i = 0; i < m_array_size; i++)
    {
      m_array_p[i] = i;
      m_array_q[i] = m_array_size - i;
      if (i == 0)
        m_array_q[i] = 1.;
    }
}

void CRat_t::print_vector ()
{
  for (int i = 0; i < m_array_size; i++)
    {
      if (m_array_p[i] == 0 || m_array_q[i] == 1)
        printf ("CRat[%d] = %2d\n", i, m_array_p[i]);
      else
        printf ("CRat[%d] = %2d / %2d\n", i, m_array_p[i], m_array_q[i]);
    }
  printf ("\n");
}

CRat_t CRat_t::operator+ (CRat_t &rhs)
{
  if (m_array_size != rhs.m_array_size)
    return *this;

  std::unique_ptr<int []> array_p_temp (new int [m_array_size]);
  std::unique_ptr<int []> array_q_temp (new int [m_array_size]);

  for (int i = 0; i < m_array_size; i++)
    {
      array_p_temp[i] = m_array_p[i] * rhs.m_array_q[i] + rhs.m_array_p[i] * m_array_q[i];
      array_q_temp[i] = m_array_q[i] * rhs.m_array_q[i];
    }

  return CRat_t (array_p_temp.get (), array_q_temp.get (), m_array_size);
}

CRat_t CRat_t::operator- (CRat_t &rhs)
{
  if (m_array_size != rhs.m_array_size)
    return *this;

  std::unique_ptr<int []> array_p_temp (new int [m_array_size]);
  std::unique_ptr<int []> array_q_temp (new int [m_array_size]);

  for (int i = 0; i < m_array_size; i++)
    {
      array_p_temp[i] = m_array_p[i] * rhs.m_array_q[i] - rhs.m_array_p[i] * m_array_q[i];
      array_q_temp[i] = m_array_q[i] * rhs.m_array_q[i];
    }

  return CRat_t (array_p_temp.get (), array_q_temp.get (), m_array_size);
}

double CRat_t::operator* (CRat_t &rhs)
{
  if (m_array_size != rhs.m_array_size)
    return 0.;

  int sum_p = 0., temp_p;
  int sum_q = 0., temp_q;

  for (int i = 0; i < m_array_size; i++)
    {
      temp_p = m_array_p[i] * rhs.m_array_p[i];
      temp_q = m_array_q[i] * rhs.m_array_q[i];

      if (temp_p != 0)
        {
          if (sum_p == 0)
            {
              sum_p = temp_p;
              sum_q = temp_q;
            }
          else
            {
              sum_p = sum_p * temp_q + temp_p * sum_q;
              sum_q = sum_q * temp_q;
            }
        }
    }

  return (double) sum_p / sum_q;
}

CRat_t& CRat_t::operator= (CRat_t &rhs)
{
  if (m_array_size > 0)
    {
      if (m_array_p)
        delete [] m_array_p;
      if (m_array_q)
        delete [] m_array_q;

      m_array_size = 0;
    }

  m_array_size = rhs.m_array_size;
  m_array_p = new int [m_array_size];
  m_array_q = new int [m_array_size];
  memcpy (m_array_p, rhs.m_array_p, m_array_size * sizeof (int));
  memcpy (m_array_q, rhs.m_array_q, m_array_size * sizeof (int));

  return *this;
}

