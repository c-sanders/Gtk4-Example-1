#ifndef UI_WIDGETS_HPP
#define UI_WIDGETS_HPP


#include <gtk/gtk.h>


extern
GtkBuilder         * builder_p;

extern
GtkWidget          * widget_boxLayout_top_p,
                   * button_p,
                   * button_quit_p,
                   * drawingArea_p;

extern
GtkEventController * gesture_left_mouse_button_click_EventController_p,
                   * gesture_right_mouse_button_click_EventController_p;


#endif
