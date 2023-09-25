#ifndef WIDGETS_HPP
#define WIDGETS_HPP


#include <gtk/gtk.h>


namespace
ns_main
{
    // Function(s) : Main::main
    //               SignalHandlers::slot_shutdown

    extern
    GApplication * app_p;
}

extern
GtkWidget          * window_p;

extern
GtkWidget          * widget_boxLayout_top_p,
                   * button_p,
                   * button_quit_p,
                   * drawingArea_p;

extern
GtkBuilder         * builder_p;

extern
GtkEventController * gesture_left_mouse_button_click_EventController_p,
                   * gesture_right_mouse_button_click_EventController_p;


#endif
