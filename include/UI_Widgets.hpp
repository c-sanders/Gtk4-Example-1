#ifndef UI_WIDGETS_HPP
#define UI_WIDGETS_HPP


#include <gtk/gtk.h>


extern
GtkBuilder         * builder_p;

extern
GtkWidget          * widget_boxLayout_top_p,
                   * button_test_1_p,
                   * button_test_2_p,
                   * button_quit_p;

// Each one of these Event Controllers should be associated with a widget.

extern
GtkEventController * eventController_right_mouse_button_pressed,
                   * eventController_right_mouse_button_released;


#endif
