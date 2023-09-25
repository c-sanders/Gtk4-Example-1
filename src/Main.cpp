#include <Main.hpp>

using ns_main::app_p;


int
main
(
 int      argc,
 char * * argv
)
{
    int   status;


    // Create an object of class type GtkApplication.
    //
    // GtkApplication is a type of GApplication. Cast it anyway in order to keep
    // the compiler happy.

    app_p
    =
    G_APPLICATION
    (
        gtk_application_new
        (
            "com.gravitas-toolworks.example-1",
            G_APPLICATION_DEFAULT_FLAGS
        )
    );

    g_signal_connect
    (
     app_p,
     "activate",
     G_CALLBACK(activate),
     NULL
    );

    status = g_application_run
             (
              G_APPLICATION(app_p),
              argc,
              argv
             );

    g_object_unref(app_p);


    return status;
}
