#ifndef __CRat_T_HPP_INCLUDED__
#define __CRat_T_HPP_INCLUDED__

#include <memory>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <limits>

class CRat_t
{
private:
  double *m_array_p;
  double *m_array_q;
  int m_array_size;

public:
  CRat_t (int array_size);
  CRat_t (double *array_p, double *array_q, int array_size);
  ~CRat_t ();

  double *get_array_p ();
  double *get_array_q ();
  int get_array_size ();

  void set_array_p (double *array_p);
  void set_array_q (double *array_q);
  void set_array_size (int array_size);

  void init_vector ();
  void print_vector ();

  CRat_t operator+ (CRat_t &rhs);
  CRat_t operator- (CRat_t &rhs);
  CRat_t operator* (CRat_t &rhs);
  CRat_t& operator= (CRat_t &rhs);

};

#endif // __CRat_T_HPP_INCLUDED__
