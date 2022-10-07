#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *fixed;
    gtkWidgrt *labelBin, *labelDec, *labelOcta, *labelhexa;
    GtkWidget *txtBin, *txtOcta, *txtHexa, *txtDec;
    GtkWidget *buttonBox, button;

    // Create container
    fixed = gtk_fixed_new();

    // Create buton component
    buttonBox = gtk_box_button_new();
    button = gtk_button_new_with_label("Calcular");
    gtk_container_add(GTK_CONTAINER(buttonBox), button);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBox, 140, 500);

    // Create entry text with label 
    txtBin = gtk_entry_new();
    labelBin = gtk_label_new("Binario");

    txtOcta = gtk_entry_new();
    labelOctal = gtk_label_new("Octal");
    labelOcta = gtk
    txtHexa = gtk_entry_new();
    labelHexa = gtk_label_new("Hexadecimal");
    txtDec = gtk_entry_new();
    labelDecl = gtk_label_new("decimal");

    gtk_fixed_put(GTK_FIXED(fixed), txtBin, 120, 100);
    gtk_fixed_put(GTK_FIXED(fixed), txtOcta, 120, 200);
    gtk_fixed_put(GTK_FIXED(fixed), txtDec, 120, 300);
    gtk_fixed_put(GTK_FIXED(fixed), txtHexa, 120, 400);

    gtk_fixed_put(GTK_FIXED(fixed), txtBin, 130, 100);
    gtk_fixed_put(GTK_FIXED(fixed), txtDec, 130, 300);
    gtk_fixed_put(GTK_FIXED(fixed), txtHexa, 130, 400);
    gtk_fixed_put(GTK_FIXED(fixed), txtOct, 130, 200);

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