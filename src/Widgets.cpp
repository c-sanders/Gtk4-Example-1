#include <Widgets.hpp>


namespace
ns_main
{
    GApplication   * app_p;
}

GtkWidget          * window_p;

GtkWidget          * widget_boxLayout_top_p,
                   * button_p,
                   * button_quit_p,
                   * drawingArea_p;

GtkBuilder         * builder_p;


GtkEventController * gesture_left_mouse_button_click_EventController_p,
                   * gesture_right_mouse_button_click_EventController_p;
