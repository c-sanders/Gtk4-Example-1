#ifndef UISPECIFIC_HPP
#define UISPECIFIC_HPP


#include <gtk/gtk.h>

#include <Widgets.hpp>
#include <SignalHandlers.hpp>


extern
GtkWidget * widget_boxLayout_top_p,
          * button_p,
          * button_quit_p,
          * drawingArea_p;


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
}


#endif
