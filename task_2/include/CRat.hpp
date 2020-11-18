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
  int *m_array_p;
  int *m_array_q;
  int m_array_size;

public:
  CRat_t (int array_size);
  CRat_t (int *array_p, int *array_q, int array_size);
  ~CRat_t ();

  int *get_array_p ();
  int *get_array_q ();
  int get_array_size ();

  void set_array_p (int *array_p);
  void set_array_q (int *array_q);
  void set_array_size (int array_size);

  void init_vector ();
  void print_vector ();

  CRat_t operator+ (CRat_t &rhs);
  CRat_t operator- (CRat_t &rhs);
  double operator* (CRat_t &rhs);
  CRat_t& operator= (CRat_t &rhs);

};

#endif // __CRat_T_HPP_INCLUDED__
