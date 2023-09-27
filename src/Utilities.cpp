#include <Utilities.hpp>


void
utilities::readUserInterfaceIntoBuilder
(
)
{
    // Open a UI file and read its contents into the Builder object.

    builder_p
    =
    gtk_builder_new_from_file
    (
        nameUIFile.c_str()
    );
}


int
utilities::configureMainWindow
(
)
{
    gtk_window_set_title
    (
        GTK_WINDOW(window_p),
        windowTitle.c_str()
    );

    gtk_window_set_default_size
    (
        GTK_WINDOW(window_p),
        windowWidth,
        windowHeight
    );


    return 0;
}


// -------------------------------------------------------------------------
// Can multiple gestures be associated with the same Widget?
// 
// For example, is it possible to associate a left mouse button click
// gesture and a right mouse button click gesture with the same widget? 
// -------------------------------------------------------------------------

// What type of Controller should be created?
//
//   - GtkEventControllerKey
//   - GtkPadController
//
// Or doesn't it even matter? How about GtkGestureSingle?
//
// Refer to;
//
//   https://discourse.gnome.org/t/how-to-claim-right-click-gestures-released-event-in-gtk4/4194/4

/*
int
utilities::createAndConfigureMouseButtonEventController
(
 GtkEventController * eventController_p,
 int                  mouseButtonNumber,
 const
 string               gestureDescription,
 GtkWidget          * associatedWidget_p,
 const
 string               eventType
)
{
    const
    string   nameFunction = "createAndConfigureMouseButtonEventController",
             nF           = nameFunction + " : ";


    // CODE REMOVED FROM HERE.

    // Can use   : pressed, released
    // Can't use : clicked

    g_signal_connect
    (
     eventController_p,
     eventType.c_str(),
     G_CALLBACK(slot_mouseButtonAction),
     NULL
    );

    return 0;
}
 */


void
utilities::connectSignalsToSlots
(
)
{
    uiSpecificConnectSignalsToSlots();

    // Connect a signal to a slot.
    // 
    // window_p->destroy ==> slot_shutdown  
    // 
    // In this connection, the slot will be invoked with;
    //
    //   - window_p passed as the first argument
    //   - app_p passed as the second argument

    g_signal_connect
    (
        window_p,
        "destroy",
        G_CALLBACK(slot_shutdown),
        NULL
    );
}
