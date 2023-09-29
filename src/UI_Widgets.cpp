#include <UI_Widgets.hpp>


GtkBuilder         * builder_p;

GtkWidget          * widget_boxLayout_top_p,
                   * button_test_1_p,
                   * button_test_2_p,
                   * button_quit_p,
                   * drawingArea_p;

GtkEventController * eventController_right_mouse_button_pressed,
                   * eventController_right_mouse_button_released;