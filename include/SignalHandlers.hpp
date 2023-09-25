#ifndef SIGNALHANDLERS_HPP
#define SIGNALHANDLERS_HPP


#include <iostream>
#include <string>

#include <gtk/gtk.h>

#include <Settings.hpp>
#include <Widgets.hpp>
#include <Utilities.hpp>

using std::cout;
using std::endl;
using std::string;


void
activate
(
    GtkApplication * app,
    gpointer         user_data
);


// Function slot_shutdown should have the following function signature.

void
slot_shutdown
(
    GtkWidget * emitting_widget_p,
    gpointer    user_data
);


#endif
