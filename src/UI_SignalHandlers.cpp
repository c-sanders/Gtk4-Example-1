#include <UI_SignalHandlers.hpp>


void
slot_mouseButtonAction
(
 GtkGestureClick * app,
 gpointer          user_data  // Does this value represent the number which
                              // corresponds to the mouse button which has been
                              // clicked, or does it represent the number of
                              // clicks which have been performed in a particular
                              // amount of time?
)
{
    const
    string         nameFunction = "slot_mouseButtonAction",
                   nF           = nameFunction + " : ";

    GtkWidget    * widget_p     = NULL;

    GdkDevice    * device_p     = NULL;

    GdkEvent     * event_p      = NULL;

    GdkEventType   eventType;


    // Parameter user_data receives a value of 1. Does this denote that the left
    // button has been clicked?

    cout << nF << "Enter" << endl;

    widget_p = gtk_event_controller_get_widget(gesture_right_mouse_button_click_EventController_p);
    device_p = gtk_event_controller_get_current_event_device(gesture_right_mouse_button_click_EventController_p);
    event_p  = gtk_event_controller_get_current_event(gesture_right_mouse_button_click_EventController_p);

    // Gdk Event types. Refer to https://docs.gtk.org/gdk4/enum.EventType.html

    eventType = gdk_event_get_event_type(event_p);

    // Reset the Controller, otherwise it gets stuck in a particular state and
    // won't handle anymore mouse button clicks.

    gtk_event_controller_reset(gesture_right_mouse_button_click_EventController_p);

    cout << nF << "Address of Event Controller object = " << widget_p << endl;
    cout << nF << "Value passed to parameter user_data = " << user_data << endl;

    cout << nF << "Name of Controller widget = " << gtk_event_controller_get_name(gesture_right_mouse_button_click_EventController_p) << endl;

    cout << nF << "Name of device = " << gdk_device_get_name(device_p) << endl;
    cout << nF << "Event type = " << eventType << endl;
    cout << nF << "Exit" << endl;
}
