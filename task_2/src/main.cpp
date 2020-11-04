
#include "../include/CRat.hpp"
#include "../include/test.hpp"

#define VECTOR_SIZE 3

int main ()
{
  CRat_t vector0 (VECTOR_SIZE);
  vector0.init_vector ();
  printf ("VECTOR_0:\n");
  vector0.print_vector ();

  CRat_t vector1 (VECTOR_SIZE);
  vector1.init_vector ();
  printf ("VECTOR_1:\n");
  vector1.print_vector ();

  CRat_t vector2 = vector0 + vector1;
  printf ("VECTOR_0 + VECTOR_1:\n");
  vector2.print_vector ();

  CRat_t vector3 = vector0 - vector1;
  printf ("VECTOR_0 - VECTOR_1:\n");
  vector3.print_vector ();

  printf ("VECTOR_0 * VECTOR_1: %2.4lf\n", vector0 * vector1);

  CRat_t vector4;
  CRat_t vector5 ();

  autotest ();
  return 0;
}
