#ifndef UI_UTILITIES_HPP
#define UI_UTILITIES_HPP


#include <gtk/gtk.h>

#include <SignalHandlers.hpp>
// Function(s) : slot_shutdown
#include <UI_Widgets.hpp>
#include <UI_SignalHandlers.hpp>


namespace
utilities
{
    int
    associateEventControllerWithWidgets
    (
    );

    int
    associateWidgetsWithBuilderObjects
    (
    );

    void
    uiSpecificConnectSignalsToSlots
    (
    );
}


#endif
