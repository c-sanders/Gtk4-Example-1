#include <UI_Utilities.hpp>


int
utilities::associateWidgetsWithBuilderObjects
(
)
{
    // Associate Widget pointers with the relevant Builder objects that were
    // loaded from the UI file. 

    widget_boxLayout_top_p =
    GTK_WIDGET
    (
        gtk_builder_get_object
        (
            const_cast<GtkBuilder*>(builder_p),
            "box_layout_vertical"
        )
    );

    button_test_1_p
    =
    GTK_WIDGET
    (
        gtk_builder_get_object
        (
            const_cast<GtkBuilder*>(builder_p),
            "button_test_1"
        )
    );

    button_test_2_p
    =
    GTK_WIDGET
    (
        gtk_builder_get_object
        (
            const_cast<GtkBuilder*>(builder_p),
            "button_test_2"
        )
    );

    button_quit_p
    =
    GTK_WIDGET
    (
        gtk_builder_get_object
        (
            const_cast<GtkBuilder*>(builder_p),
            "button_quit"
        )
    );


    return 0;
}


void
utilities::uiSpecificConnectSignalsToSlots
(
)
{
    // Connect a signal to a slot.
    // 
    // button_quit_p->clicked ==> slot_shutdown  
    // 
    // In this connection, the slot will be invoked with;
    //
    //   - button_quit_p passed as the first argument
    //   - app_p passed as the second argument

    g_signal_connect
    (
        button_quit_p,
        "clicked",
        G_CALLBACK(slot_shutdown),
        NULL
    );
}


int
// utilities::associateEventControllerWithWidgets
utilities::button_test_1_right_press
(
    const
    string   nameInvokingFunction
)
{
    const
    string   nameFunction = "utilities::associateEventControllerWithWidgets",
             nF           = nameFunction + " : ";


    // Create a new Event Controller and associate it with the Quit Button
    // widget.
    //
    // This Event Controller should handle any right mouse button clicks which
    // are performed on the Quit Button.
    //
    // Event Controllers refer to the action of clicking a button as "pressed"
    // not "clicked".

    // >>> Create a new Evemt Controller.

    eventController_right_mouse_button_pressed
    =
    GTK_EVENT_CONTROLLER
    (
        gtk_gesture_click_new()
    );

    // >>> Tell the Event Controller which events it should be listening out
    //     for.
    //
    // Instruct the Event Controller to only capture right mouse button clicks.
    // The number 3 denotes the right mouse button.

    cout << nF << "About to associate a button with the Event Controller" << endl;

    gtk_gesture_single_set_button
    (
        GTK_GESTURE_SINGLE(eventController_right_mouse_button_pressed),
        3
    );

    cout << nF << "Have associated a button with the Event Controller" << endl;

    // >>> Assign a human-friendly name to the Event Controller.

    gtk_event_controller_set_name
    (
        eventController_right_mouse_button_pressed,
        "Right Mouse Button Press - Event Handler"
    );

    // >>> Tell the Event Controller which GUI widget it should listen to for
    //     events.

    gtk_widget_add_controller
    (
        button_test_1_p,
        eventController_right_mouse_button_pressed
    );

    // Can use   : pressed, released
    // Can't use : clicked

    cout << nF << "About to connect the Event Controller to a Slot" << endl;

    // The following reference to slot_mouseButtonAction is causing problems for
    // the compiler.
    //
    // 

    g_signal_connect
    (
        eventController_right_mouse_button_pressed,
        "pressed",
        G_CALLBACK(slot_mouseButtonAction),
        NULL
    );

    cout << nF << "Have connected the Event Controller to a Slot" << endl;


    /*
    createAndConfigureMouseButtonEventController
    (
        gesture_right_mouse_button_click_EventController_p,
        3,
        "Event Controller : Right Mouse Button clicked",
        button_quit_p,
        "pressed"
    );
     */

    // Create another Controller and also associate it with the Button widget.
    //
    // This Controller should handle any left mouse button clicks which are
    // performed on the Button widget.

    /*
    gesture_left_mouse_button_click_EventController_p = GTK_EVENT_CONTROLLER
    (
        gtk_gesture_click_new()
    );

    createAndConfigureMouseButtonEventController
    (
        gesture_left_mouse_button_click_EventController_p,
        1,
        "Event Controller : Left Mouse Button clicked",
        drawingArea_p,
        "pressed"
    );
     */


    return 0;
}


int
utilities::button_test_2_right_release
(
    const
    string   nameInvokingFunction
)
{
    const
    string   nameFunction = "utilities::button_test_2_right_release",
             nF           = nameFunction + " : ";


    // Create a new Event Controller and associate it with the Quit Button
    // widget.
    //
    // This Event Controller should handle any right mouse button clicks which
    // are performed on the Quit Button.
    //
    // Event Controllers refer to the action of clicking a button as "pressed"
    // not "clicked".

    // >>> Create a new Evemt Controller.

    eventController_right_mouse_button_released
    =
    GTK_EVENT_CONTROLLER
    (
        gtk_gesture_click_new()
    );

    // >>> Tell the Event Controller which events it should be listening out
    //     for.
    //
    // Instruct the Event Controller to only capture right mouse button clicks.
    // The number 3 denotes the right mouse button.

    cout << nF << "About to associate a button with the Event Controller" << endl;

    gtk_gesture_single_set_button
    (
        GTK_GESTURE_SINGLE(eventController_right_mouse_button_released),
        3
    );

    cout << nF << "Have associated a button with the Event Controller" << endl;

    // >>> Assign a human-friendly name to the Event Controller.

    gtk_event_controller_set_name
    (
        eventController_right_mouse_button_released,
        "Right Mouse Button Release - Event Handler"
    );

    // >>> Set the Event Controller to receive events from the specified widget.

    gtk_widget_add_controller
    (
        button_test_1_p,
        eventController_right_mouse_button_released
    );

    // Can use   : pressed, released
    // Can't use : clicked

    cout << nF << "About to connect the Event Controller to a Slot" << endl;

    // I'm not sure that 2 slots can be connected to the same signal as is done
    // in the following code block.
    // 
    // It appears as though the first signal gets successfully registered, while
    // the second signal gets quitely ignored. 

    {
        g_signal_connect
        (
            eventController_right_mouse_button_released,
            "pressed",
            G_CALLBACK(slot_mouseButtonAction),
            NULL
        );

        g_signal_connect
        (
            eventController_right_mouse_button_released,
            "released",
            G_CALLBACK(slot_mouseButtonAction),
            NULL
        );
    }

    cout << nF << "Have connected the Event Controller to a Slot" << endl;


    /*
    createAndConfigureMouseButtonEventController
    (
        gesture_right_mouse_button_click_EventController_p,
        3,
        "Event Controller : Right Mouse Button clicked",
        button_quit_p,
        "pressed"
    );
     */

    // Create another Controller and also associate it with the Button widget.
    //
    // This Controller should handle any left mouse button clicks which are
    // performed on the Button widget.

    /*
    gesture_left_mouse_button_click_EventController_p = GTK_EVENT_CONTROLLER
    (
        gtk_gesture_click_new()
    );

    createAndConfigureMouseButtonEventController
    (
        gesture_left_mouse_button_click_EventController_p,
        1,
        "Event Controller : Left Mouse Button clicked",
        drawingArea_p,
        "pressed"
    );
     */


    return 0;
}