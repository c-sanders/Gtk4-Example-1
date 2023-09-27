#ifndef UTILITIES_HPP
#define UTILITIES_HPP


#include <iostream>
#include <string>

#include <gtk/gtk.h>

#include <Settings.hpp>
#include <Widgets.hpp>
#include <UI_Utilities.hpp>
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


    /*
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
     */


    void
    connectSignalsToSlots
    (
    );

}  // End of namespace : utilities


#endif
