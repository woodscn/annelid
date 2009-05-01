#include <dlfcn.h>
#include <stdio.h>

int main (int argc, char** argv)
{
  typedef int (*signature) ();

  void* so_handle = NULL;
  void* function = NULL;
  char* error = NULL;

  int retval = 0;

  so_handle = dlopen ("./libannelid_test_a.so", (RTLD_LAZY | RTLD_LOCAL));

  if (NULL == so_handle)
    {
      fprintf (stderr, "[annelid] dlopen failed: %s.", dlerror ());
    }

  dlerror ();
  function = dlsym (so_handle, "annelid_test_a_mp_annelid_test_");
  error = dlerror ();

  if (NULL != error)
    {
      fprintf (stderr, "[annelid] dlsym failed: %s.", error);
    }

  retval = ((signature) function) ();

  printf ("got: %d\n", retval);

  if (dlclose (so_handle))
    {
      fprintf (stderr, "[annelid] dlclose failed: %s.", dlerror ());
    }

  return 0;
}