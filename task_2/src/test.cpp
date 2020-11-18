
#include "../include/test.hpp"

void autotest ()
{
  CRat_t vector0 (VECTOR_SIZE);
  vector0.init_vector ();
  for (int i = 0; i < 3; i++)
    if (vector0.get_array_p ()[i] != i)
      { printf ("TEST FAILED!\n"); return; }


  CRat_t vector1 (VECTOR_SIZE);
  vector1.init_vector ();
  for (int i = 0; i < 3; i++)
    if (vector1.get_array_p ()[i] != i)
      { printf ("TEST FAILED!\n"); return; }


  CRat_t vector2 = vector0 + vector1;
  if (vector2.get_array_p ()[0] != 0)
    { printf ("TEST FAILED!\n"); return; }
  for (int i = 1; i < 3; i++)
    if (vector2.get_array_p ()[i] != 4)
      { printf ("TEST FAILED!\n"); return; }

  for (int i = 0; i < 3; i++)
    if (vector0.get_array_p ()[i] != i)
      { printf ("TEST FAILED!\n"); return; }

  for (int i = 0; i < 3; i++)
    if (vector1.get_array_p ()[i] != i)
      { printf ("TEST FAILED!\n"); return; }


  CRat_t vector3 = vector0 - vector1;
  for (int i = 0; i < 3; i++)
    if (vector3.get_array_p ()[i] != 0)
      { printf ("TEST FAILED!\n"); return; }

  if (fabs ((vector0 * vector1) - 4.25) > std::numeric_limits<double>::epsilon ())
    { printf ("TEST FAILED!\n"); return; }


  printf ("TEST PASSED!\n");
}
