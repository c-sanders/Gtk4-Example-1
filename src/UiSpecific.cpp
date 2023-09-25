#include <UiSpecific.hpp>


GtkWidget * widget_boxLayout_top_p,
          * button_p,
          * button_quit_p,
          * drawingArea_p;


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

    /*
    button_p =
    GTK_WIDGET
    (
        gtk_builder_get_object
        (
            const_cast<GtkBuilder*>(builder_p),
            "button_1"
        )
    );

    drawingArea_p =
    GTK_WIDGET
    (
        gtk_builder_get_object
        (
            const_cast<GtkBuilder*>(builder_p),
            "drawingArea"
        )
    );
     */

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
