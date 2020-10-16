
#include "../include/test.hpp"

void autotest ()
{
  CRat_t vector0 (VECTOR_TEST_SIZE);
  vector0.init_vector ();
  for (int i = 0; i < VECTOR_TEST_SIZE; i++)
    if (fabs (vector0.get_array_p ()[i] - i) > std::numeric_limits<double>::epsilon ())
      { printf ("TEST FAILED!\n"); return; }


  CRat_t vector1 (VECTOR_TEST_SIZE);
  vector1.init_vector ();
  for (int i = 0; i < VECTOR_TEST_SIZE; i++)
    if (fabs (vector1.get_array_p ()[i] - i) > std::numeric_limits<double>::epsilon ())
      { printf ("TEST FAILED!\n"); return; }


  CRat_t vector2 = vector0 + vector1;
  if (fabs (vector2.get_array_p ()[0]) > std::numeric_limits<double>::epsilon ())
    { printf ("TEST FAILED!\n"); return; }
  for (int i = 1; i < VECTOR_TEST_SIZE; i++)
    if (fabs (vector2.get_array_p ()[i] - 4) > std::numeric_limits<double>::epsilon ())
      { printf ("TEST FAILED!\n"); return; }

  for (int i = 0; i < VECTOR_TEST_SIZE; i++)
    if (fabs (vector0.get_array_p ()[i] - i) > std::numeric_limits<double>::epsilon ())
      { printf ("TEST FAILED!\n"); return; }

  for (int i = 0; i < VECTOR_TEST_SIZE; i++)
    if (fabs (vector1.get_array_p ()[i] - i) > std::numeric_limits<double>::epsilon ())
      { printf ("TEST FAILED!\n"); return; }


  CRat_t vector3 = vector0 - vector1;
  for (int i = 0; i < VECTOR_TEST_SIZE; i++)
    if (fabs (vector3.get_array_p ()[i]) > std::numeric_limits<double>::epsilon ())
      { printf ("TEST FAILED!\n"); return; }

  if (fabs ((vector0 * vector1).get_array_p ()[0] - 17.) > std::numeric_limits<double>::epsilon () ||
      fabs ((vector0 * vector1).get_array_q ()[0] - 4.) > std::numeric_limits<double>::epsilon ())
    { printf ("TEST FAILED!\n"); return; }


  printf ("TEST PASSED!\n");
}
