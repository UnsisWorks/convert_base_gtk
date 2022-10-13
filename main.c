#include <gtk/gtk.h>
#include <stdio.h>
#include <math.h>

GtkWidget *txtBin, *txtOcta, *txtHexa, *txtDec;
gchar letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

gchar binToDecimal(GString *value, int push){

    // Create objects and var nedd
    GString *afterPoint = g_string_new(value -> str);
    GString *beforePoint = g_string_new(value -> str);

    gboolean flag = FALSE;
    gfloat help = 0;
    gint pot = 0;
    gfloat result = 0;

    // Separete string for point
    for (gint i = 0; i < value->len; i++) {
        if (value -> str[i] == '.'){
            beforePoint = g_string_truncate(beforePoint, i);
            afterPoint = g_string_erase(afterPoint, 0, i + 1);
            flag = TRUE;
            break;
        } 
    }
    g_print("before: %s   After: %s  \n", beforePoint -> str, afterPoint -> str);

    // Convert part before at point
    for (gint i = (beforePoint -> len) - 1; i >= 0; i--) {
        if (beforePoint -> str[i] == '1') {
            pot = (beforePoint->len - 1) - i;
            g_print("value: %c  pot: %d  ", (beforePoint -> str[i]), pot);
            help = pow(2, pot);
            result += help;
            g_print(" =  %f +=  %f\n", help, result);
        }
    }

    if (flag) {
        help = 0;
        pot = 1;
        // Create cod after point if exist
        for (gint i = 0; i < (afterPoint -> len); i++) {
            if (afterPoint -> str[i] == '1') {
                g_print("value: %c  pot: %d  ", (afterPoint -> str[i]), pot);
                // Definition Math 2^-n = 1 / (2^n)
                help = 1 / (pow(2, pot));
                result += help;
                g_print(" =  %f +=  %f\n", help, result);
            }
            pot++;
        }
        const gchar resultado = (gchar) result;
        // g_print("bin to dec: %d\n", resultado);
    }
    // g_print("Resultado: %f\n", result);
    // const gchar *res = *result;
    gchar vali[10];
    sprintf(vali, "%f", result);
    // g_print("Resultado cad: %s\n", vali);
    const gchar *fina = vali;

    // Send request or return bvalue
    if (push == 0) {
        gtk_entry_set_text(GTK_ENTRY(txtDec), fina);
    } else {
        return vali[0];
    }
}
// Convert binary to hexadecimal
void binToHexa(GString *value){
    GString *mod = g_string_new("");
    int result;
    gint64 decimal = g_ascii_strtoll(value->str, NULL, 2);
    result = decimal;
    while (result != 0) {
        mod = g_string_append_(mod, sprintf());
        result = 
    }
    
}
// Convert binary to octal
void binToOctal(GString *value){
    GString *result =  g_string_new("");
    GString *trunc =  g_string_new("");
    GString *request = g_string_new("");;
    // Valid multipl to 3
    gint difference = 0;
    for (gint i = 3; i <= (value->len + 3); i += 3) {
        if (i >= (value->len - 1)) {
            difference = i - (value->len);
        }
    }

    // Add char's for complete multi the 3
    if (difference < 3 && difference != 0) {
        for (gint i = 1; i <= difference; i++) {
            g_string_prepend_c(value, '0');
        }
        g_print("mod cadena: %s longi: %ld\n", value->str, value->len);
    }
    // Reco value left to rigth
    gint rr = (value->len) + 3;
    for (gint i = 3; i < rr; i += 3) {
        trunc = g_string_insert(trunc, 0, value->str);
        // Recorta 3 numeros
        trunc = g_string_erase(trunc, i, 0 - 1);
        trunc = g_string_erase(trunc, 0, i - 3);
        // request = g_string_erase(request, 0, 0 - 1);
        request = g_string_append_c(request, binToDecimal(trunc, 1));
        g_print("i: %d  truc: %s; result = %s\n", i, trunc->str, request->str);

        // Vacia la cadena
        trunc = g_string_erase(trunc, 0, 0 - 1);
        // result = g_string_append(result, binToDecimal());
    }

    // Set value at entry widget
    gtk_entry_set_text(GTK_ENTRY(txtOcta), request->str);
}
// Crate new window and show messaege 
static void sendMessage (GtkWidget *widget, gchar *message, gchar *title) {
    GtkWidget *dialog, *label, *contentArea;
    GtkDialogFlags flags;

    // Create at window dialog with title, parent, flags, text in button
    dialog = gtk_dialog_new_with_buttons(title, NULL, flags, "Aceptar", GTK_RESPONSE_NONE, NULL);

    // Set properties at window dialog
    contentArea = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_window_set_default_size(GTK_WINDOW(dialog), 200, 200);
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER_ON_PARENT );
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
    label = gtk_label_new(message);
    // gtk_label

    // Close window dialog to the price button accept
    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
    // Add witget and show result
    gtk_container_add(GTK_CONTAINER(contentArea), label);
    gtk_widget_show_all(dialog);
}

// Convert input a bases rest
static void convert (int id, GString *value) {
    gboolean flag = TRUE;
    gint64 band;
    const gchar *reply;
    // Selected convert correct
    switch (id) {
        // Cast from binary to rest bases
        case 0:
            // Iterat value (except char end string '\0')
            for (gint i = 0; i <= (value->len) - 1; i++) {
                // Compare chars the object string with '0', '1' y '.'
                if (!((value->str[i] == '0') || value->str[i] == '1'/* || value->str[i] == '.'*/)) {
                    flag = FALSE;
                    break;
                }
            }

            if (flag) {
                // binToDecimal(value, 0);
                // binToOctal(value);
                // binToHexa(value);
                gint64 dec = g_ascii_strtoll(value->str, NULL, 2);
                gint64 hexa = g_ascii_strtoll(value->str, NULL, 3.5);
                gint64 octal = g_ascii_strtoll(value->str, NULL, 2.6);

                gchar decM[20];
                sprintf(decM, "%ld", dec);
                gchar hexaM[20];
                sprintf(hexaM, "%ld", hexa);
                gchar octalM[20];
                sprintf(octalM, "%ld", octal);

                gtk_entry_set_text(GTK_ENTRY(txtDec), decM);
                gtk_entry_set_text(GTK_ENTRY(txtHexa), hexaM);
                gtk_entry_set_text(GTK_ENTRY(txtOcta), octalM);

                
            } else {
                sendMessage(NULL, "Ingresar unicamente 0 y 1", "Aviso");
            }
            break;
        // Conversion for octal base
        case 1:
            g_print("before bucle octal\n");
            // Validacion para contener numeros
            for (gint i = 0; i <= (value->len) - 1; i++) {
                if (!g_ascii_isdigit(value->str[i])) {
                    flag = FALSE;
                    break;
                }
            }
            if (flag) {
                // Verificar nums < 8
                for (gint i = 0; i < value -> len; i++) {
                    if (!((value -> str[i]) < '8')) {
                        flag = FALSE;
                        break;
                    }
                }
                if (flag) {
                    g_print("Continue\n");
                    // Funcion para convertir de gstring a numero dep. la base. 0 para convertir tal cual
                    gint64 valInt = g_ascii_strtoll(value->str, NULL, 0);
                    g_print("%ld\n", valInt);

                    gint64 dec = g_ascii_strtoll(value->str, NULL, 10);
                    gint64 hexa = g_ascii_strtoll(value->str, NULL, 16);
                    gint64 bin = g_ascii_strtoll(value->str, NULL, 2);

                    gchar decM[20];
                    sprintf(decM, "%ld", dec);
                    gchar hexaM[20];
                    sprintf(hexaM, "%ld", hexa);
                    gchar binM[20];
                    sprintf(binM, "%ld", bin);

                    gtk_entry_set_text(GTK_ENTRY(txtDec), decM);
                    gtk_entry_set_text(GTK_ENTRY(txtHexa), hexaM);
                    gtk_entry_set_text(GTK_ENTRY(txtBin), binM);

                } else {
                    sendMessage(NULL, "La base octal opera en el rango de numeros 0 - 7", "Advertencia");
                }
            } else {
                sendMessage(NULL, "La base octal solo debe contener numeros", "Aviso");
            }
            break;
        // Verification for base hexadecimal 
        case 2:
            g_string_ascii_up(value);
            g_print("val: %s\n", value->str);
            flag = FALSE;
            gint coin = 0;
            for (gint i = 0; i < value -> len; i++) {
                // Validation for digit's
                if (g_ascii_isdigit(value->str[i])) {
                    // g_print("Digit\n");
                    if (!((value->str[i] <= 9) && (value->str[i] >= 0))) {
                        // g_print("digit on core\n");
                        coin++;
                    }
                // Validation for letters
                } else {
                    g_print("letter \n");
                    for (gint j = 0; j <= 5; j++) {
                        if (value->str[i] == letters[j]) {
                            flag = TRUE;
                            coin++;
                        } 
                    }
                }
            }
            // Decition final
            if (coin == (value -> len)) {
                g_print("continue\n");
                /* Convert actal to rest bases */
            } else {
                sendMessage(NULL, "Numero octal no valido", "Aviso");
            }
            break;
        case 3:
            band = g_ascii_strtoll(value -> str, NULL, 0);
            g_print("cod: %ld\n", band);
            if (band != 0) {
                g_print("continue\n");
                /* Convert decimal to rest bases */
            } else {
                sendMessage(NULL, "El decimal debe ser un numero diferente de 0", "Aviso");
            }
            break;
        default:
            break;
    }
}

// Funtion execute press button 'convertir'
static void calcular(GtkWidget *widget, gpointer data) {
    int count = 0;
    int id = 0;
    const gchar *value;
    // Get text the entry witgets
    const gchar *bin = gtk_entry_get_text(GTK_ENTRY(txtBin));
    const gchar *octal = gtk_entry_get_text(GTK_ENTRY(txtOcta));
    const gchar *deci = gtk_entry_get_text(GTK_ENTRY(txtDec));
    const gchar *hexa = gtk_entry_get_text(GTK_ENTRY(txtHexa));
    
    // Validacion de datos enviados a 1
     if ((strcmp(bin, "") != 0)) {  
        count++;
        id = 0;
        value = bin;
    }
     if ((strcmp(octal, "") != 0)) {
        count++;
        id = 1;
        value = octal;
    }
     if ((strcmp(hexa, "") != 0)) {
        count++;
        id = 2;
        value = hexa;
    }
     if ((strcmp(deci, "") != 0)) {
        count++;
        id = 3;
        value = deci;
    }
    // num inputs need?
    if (count == 1) {
        GString *str = g_string_new(value);
        convert(id, str);
    } else {
        sendMessage(widget, "Solo debe ingresar un dato", "Advertencia");
    }
}
// Funtion construct
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *labelBin, *labelDec, *labelOcta, *labelHexa;
    GtkWidget *buttonBox, *button;

    // Create container
    fixed = gtk_fixed_new();

    // Create buton component
    buttonBox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    button = gtk_button_new_with_label("Calcular");
    g_signal_connect (button, "clicked", G_CALLBACK (calcular), NULL);

    gtk_container_add(GTK_CONTAINER(buttonBox), button);
    // add button and set position in fixed 
    gtk_fixed_put(GTK_FIXED(fixed), buttonBox, 250, 500);

    // Create entry text with label 
    txtBin = gtk_entry_new();
    labelBin = gtk_label_new("Binario");

    txtOcta = gtk_entry_new();
    labelOcta = gtk_label_new("Octal");

    txtHexa = gtk_entry_new();
    labelHexa = gtk_label_new("Hexadecimal");

    txtDec = gtk_entry_new();
    labelDec = gtk_label_new("decimal");

    // Add witgets at fixed with position
    gtk_fixed_put(GTK_FIXED(fixed), txtBin, 220, 100);
    gtk_fixed_put(GTK_FIXED(fixed), txtOcta, 220, 200);
    gtk_fixed_put(GTK_FIXED(fixed), txtDec, 220, 300);
    gtk_fixed_put(GTK_FIXED(fixed), txtHexa, 220, 400);

    gtk_fixed_put(GTK_FIXED(fixed), labelBin, 220, 85);
    gtk_fixed_put(GTK_FIXED(fixed), labelOcta, 220, 185);
    gtk_fixed_put(GTK_FIXED(fixed), labelDec, 220, 285);
    gtk_fixed_put(GTK_FIXED(fixed), labelHexa, 220, 385);

    // Create window aplication
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    // add container at window
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Show all widgets
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    // init window at app
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

// Compiler: gcc `pkg-config --cflags gtk+-3.0` -o auto main.c `pkg-config --libs gtk+-3.0` -lm
// https://calcifer.org/documentos/librognome/glib-strings.html 