
#include "../include/CRat.hpp"
#include "../include/test.hpp"

int main ()
{
  CRat_t vector0;
  vector0.init_vector ();
  printf ("VECTOR_0:\n");
  vector0.print_vector ();

  CRat_t vector1;
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

  autotest ();
  return 0;
}
