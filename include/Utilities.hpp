#ifndef UTILITIES_HPP
#define UTILITIES_HPP


#include <iostream>
#include <string>

#include <gtk/gtk.h>

#include <Widgets.hpp>
#include <SignalHandlers.hpp>

using std::cout;
using std::endl;
using std::string;


namespace utilities
{
    void
    readUserInterfaceIntoBuilder
    (
    );


    int
    associateWidgetsWithBuilderObjects
    (
    );


    int
    configureMainWindow
    (
    );


    int
    associateEventControllerWithWidgets
    (
    );


    int
    createAndConfigureMouseButtonEventController
    (
     GtkEventController * eventController_p,
     int                  mouseButtonNumber,
     const
     string               gestureDescription,
     GtkWidget          * associatedWidget_p,
     const
     string               eventType
    );


    void
    slot_mouseButtonAction
    (
     GtkApplication * app,
     gpointer         user_data  // Does this value represent the number which
                                 // corresponds to the mouse button which has been
                                 // clicked, or does it represent the number of
                                 // clicks which have been performed in a particular
                                 // amount of time?
    );


    void
    connectSignalsToSlots
    (
    );

}  // End of namespace : utilities


#endif
