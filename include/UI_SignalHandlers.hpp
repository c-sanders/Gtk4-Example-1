#ifndef UI_SIGNALHANDLERS_HPP
#define UI_SIGNALHANDLERS_HPP


#include <iostream>
#include <string>

#include <gtk/gtk.h>

#include <UI_Widgets.hpp>


using std::cout;
using std::endl;
using std::string;


void
slot_mouseButtonAction
(
    GtkEventController * emittingWidget_p,
    gpointer             user_data  // Does this value represent the number which
                                    // corresponds to the mouse button which has been
                                    // clicked, or does it represent the number of
                                    // clicks which have been performed in a particular
                                    // amount of time?
);


// Function slot_shutdown should have the following function signature.

void
slot_pressed_right_button
(
    GtkWidget * emitting_widget_p,
    gpointer    user_data
);


#endif
