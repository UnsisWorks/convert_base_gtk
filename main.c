#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *txtBin, *txtOcta, *txtHexa, *txtDec;
    GtkWidget *buttonBox, button;

    // Create container
    fixed = gtk_fixed_new();

    // Create buton component
    buttonBox = gtk_box_button_new();
    button = gtk_button_new_with_label("Calcular");
    gtk_container_add(GTK_CONTAINER(buttonBox), button);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBox, 140, 500);
    // Create entry text
    txtBin = gtk_entry_new();
    txtOcta = gtk_entry_new();
    txtHexa = gtk_entry_new();
    txtDec = gtk_entry_new();

    gtk_fixed_put(GTK_FIXED(fixed), txtBin, 120, 100);
    gtk_fixed_put(GTK_FIXED(fixed), txtOcta, 120, 200);
    gtk_fixed_put(GTK_FIXED(fixed), txtDec, 120, 300);
    gtk_fixed_put(GTK_FIXED(fixed), txtHexa, 120, 400);

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

    // add container at window
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Show all widgets
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}