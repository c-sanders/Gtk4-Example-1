#ifndef UI_UTILITIES_HPP
#define UI_UTILITIES_HPP


#include <gtk/gtk.h>

#include <SignalHandlers.hpp>
// Function(s) : slot_shutdown
#include <UI_Widgets.hpp>
#include <UI_SignalHandlers.hpp>


/**
 * Utilities class.
 *
 * This class provides methods that implement a range of utility functions.
 * 
 * The functionality implemented by these functions includes;
 * 
 *   - associating widgets with Gtk4 builder objects,
 *   - connecting signals from UI specific widgets to slots,
 *   - creating Event Controllers, configuring them, and then connecting them
 *     to widget signals.
 */


class
Utilities
{
public :

    // Ctor

    Utilities
    (
    );

    // Dtor

    ~Utilities
    (
    );

    // Copy Ctor

    Utilities
    (
        const
        Utilities& rhs
    );

    // Operator =

    Utilities
    operator=
    (
        const
        Utilities & rhs
    );


public :

    int
    button_test_1_right_press
    (
        const
        string   nameInvokingFunction
    );
};


namespace
utilities
{
    int
    associateWidgetsWithBuilderObjects
    (
    );

    void
    uiSpecificConnectSignalsToSlots
    (
    );

    int
    // associateEventControllerWithWidgets
    button_test_1_right_press
    (
        const
        string   nameInvokingFunction
    );

    int
    // associateEventControllerWithWidgets
    button_test_2_right_release
    (
        const
        string   nameInvokingFunction
    );
}


#endif
