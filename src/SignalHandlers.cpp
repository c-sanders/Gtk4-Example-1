#include <SignalHandlers.hpp>


void
activate
(
 GtkApplication * app_p,
 gpointer         user_data
)
{
    window_p = gtk_application_window_new(app_p);

    utilities::readUserInterfaceIntoBuilder();

    utilities::associateWidgetsWithBuilderObjects();

    utilities::connectSignalsToSlots();

    utilities::configureMainWindow();

    utilities::associateEventControllerWithWidgets();

    // Set the main widget for the window. 

    gtk_window_set_child
    (
     GTK_WINDOW(window_p),
     GTK_WIDGET(widget_boxLayout_top_p)
    );

    // Does gtk_widget_set_visible need to be invoked at this point? 

    gtk_widget_show(window_p);
}
 

void
slot_shutdown
(
    GtkWidget * emitting_widget_p,
    gpointer    user_data
)
{
    const
    string         nameFunction = "slot_shutdown",
                   nF           = nameFunction + " : ";


    cout << nF << "Enter" << endl;

    if (G_IS_APPLICATION(emitting_widget_p))
    {
        cout << nF << "emitting_widget_p is of type GApplication *" << endl;
    }
    else
    if (GTK_IS_APPLICATION_WINDOW(emitting_widget_p))
    {
        cout << nF << "emitting_widget_p is of type GtkApplicationWindow *" << endl;
    }
    else
    if (GTK_IS_BUTTON(emitting_widget_p))
    {
        cout << nF << "emitting_widget_p is of type GtkButton *" << endl;
    }
    else
    {

    }

    // cout << nF << "Value of app_p     = " << app_p << endl;
    cout << nF << "Value of user_data = " << user_data << endl;

    // This is probably not the best way to exit the application, but it will
    // do for the time being.

    g_application_quit(G_APPLICATION(ns_main::app_p));

    cout << nF << "Exit" << endl;
}
