#include <gtk/gtk.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

GtkWidget *txtBin, *txtOcta, *txtHexa, *txtDec, *txtBcd , *buttonClear, *buttonClearBox;
gchar letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
int bandCheck = 0;

gchar binToDecimal(GString *value, int push){

    // Create objects and var nedd
    GString *afterPoint = g_string_new(value -> str);
    GString *beforePoint = g_string_new(value -> str);

    gboolean flag = FALSE;
    gfloat help = 0;
    gint pot = 0;
    gint result = 0;

    // Separete string for point
    for (gint i = 0; i < value->len; i++) {
        if (value -> str[i] == '.'){
            beforePoint = g_string_truncate(beforePoint, i);
            afterPoint = g_string_erase(afterPoint, 0, i + 1);
            flag = TRUE;
            break;
        } 
    }
    // g_print("before: %s   After: %s  \n", beforePoint -> str, afterPoint -> str);

    // Convert part before at point
    for (gint i = (beforePoint -> len) - 1; i >= 0; i--) {
        if (beforePoint -> str[i] == '1') {
            pot = (beforePoint->len - 1) - i;
            // g_print("value: %c  pot: %d  ", (beforePoint -> str[i]), pot);
            help = pow(2, pot);
            result += help;
            // g_print(" =  %f +=  %d\n", help, result);
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
                g_print(" =  %f +=  %d\n", help, result);
            }
            pot++;
        }
        const gchar resultado = (gchar) result;
        // g_print("bin to dec: %d\n", resultado);
    }
    // g_print("Resultado: %f\n", result);
    // const gchar *res = *result;
    gchar vali[10];
    sprintf(vali, "%d", result);
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
void DecToHexaOcta(GString *value, int base){

    GString *mod = g_string_new("");
    int result;
    gint64 decimal = g_ascii_strtoll(value->str, NULL, 2);
    g_print("decimal: %ld\n", decimal);
    result = decimal;
    char aux[10];

    while (result != 0) {
        // g_print("itera\n");
        // g_print("%d / 16 =", result );
        sprintf(aux, "%d", (result % base));
        result = result / base;
        g_print("mod: %s\n", aux);

        if (strcmp(aux, "10") == 0) {
            strcpy(aux, "A");
        } else
        if (strcmp(aux, "11") == 0) {
            strcpy(aux, "B");
        } else
        if (strcmp(aux, "12") == 0) {
            strcpy(aux, "C");
        } else
        if (strcmp(aux, "13") == 0) {
            strcpy(aux, "D");
        } else
        if (strcmp(aux, "14") == 0) {
            strcpy(aux, "E");
        } else
        if (strcmp(aux, "15") == 0) {
            strcpy(aux, "F");
        } else {
            g_print("normal ");
        }
        g_print("mod2: %s\n", aux);
        
        mod = g_string_prepend(mod, aux);
    }
    if (base == 16) {
        gtk_entry_set_text(GTK_ENTRY(txtHexa), mod->str);
    } else if (base == 8) {
        gtk_entry_set_text(GTK_ENTRY(txtOcta), mod->str);
    } else if (base == 2){
        gtk_entry_set_text(GTK_ENTRY(txtBin), mod->str);
    }
}


// Convert Decimal direct to hexadecimal and octal
void DecToHexaOctaDirect(gint64 decimal, int base){
    GString *mod = g_string_new("");
    int result;
    result = decimal;
    char aux[10];
    while (result != 0) {
        // Conversión y obtención de modulo
        sprintf(aux, "%d", (result % base));
        result = result / base;
        g_print("mod: %s\n", aux);

        // Validación para base Hexadecimal
        if (strcmp(aux, "10") == 0) {
            strcpy(aux, "A");
        } else if (strcmp(aux, "11") == 0) {
            strcpy(aux, "B");
        } else if (strcmp(aux, "12") == 0) {
            strcpy(aux, "C");
        } else if (strcmp(aux, "13") == 0) {
            strcpy(aux, "D");
        } else if (strcmp(aux, "14") == 0) {
            strcpy(aux, "E");
        } else if (strcmp(aux, "15") == 0) {
            strcpy(aux, "F");
        } else {
            g_print("normal ");
        }
        g_print("mod2: %s\n", aux);
        
        mod = g_string_prepend(mod, aux);
    }
    // Asignación del valor a la salida correspondiente
    if (base == 16) {
        gtk_entry_set_text(GTK_ENTRY(txtHexa), mod->str);
    } else if (base == 8) {
        gtk_entry_set_text(GTK_ENTRY(txtOcta), mod->str);
    } else if (base == 2){
        gtk_entry_set_text(GTK_ENTRY(txtBin), mod->str);
    }
}

// Octal to Decimal
gint64 OctalToDecimal(GString *value, int flag) {
    gint64 result = 0;
    int pot = 0;
    int aux = 0;
    char v;
    // Rocort left to rigth octal number
    for (gint i = (value->len - 1); i >= 0; i--) {
        pot = (value->len - 1) - i;
        // n * 8^pot
        v = (value->str[i]);
        aux = atoi(&v);
        result += aux * (pow(8, pot));
        g_print("%d * 8 ^ %d = %ld\n", aux, pot, result);
    }
    
    if(flag == 0) {
        gchar res[20];
        sprintf(res, "%ld", result);
        gtk_entry_set_text(GTK_ENTRY(txtDec), res);
    } else {
        return result;
    }
}

// Convert decimal to binary
gint64 hexaToDec(GString *value, int flag) {
    int pot = 0;
    char aux;
    int digit = 0;
    gint64 result = 0;

    // invert value
    for (gint i = (value->len - 1); i >= 0; i--) {
        pot = (value->len - 1) - i;
        aux = (value->str[i]);
        if (g_ascii_isdigit(value->str[i])) {
            digit = atoi(&aux);
            result += digit * (pow(16, pot));
        } else {
            // Convert char to int
            if (aux == 'A') {
                digit = 10;
            } else if (aux == 'B') {
                digit = 11;
            } else if (aux == 'C') {
                digit = 12;
            } else if (aux == 'D') {
                digit = 13;
            } else if (aux == 'E') {
                digit = 14;
            } else if (aux == 'F') {
                digit = 15;
            }
            result += digit * (pow(16, pot));
        }
        g_print("%c * 16^%d = %ld\n", aux, pot, result);
    }
    if (flag == 0) {
        gchar res[20];
        sprintf(res, "%ld", result);
        gtk_entry_set_text(GTK_ENTRY(txtDec), res);
    } else {
        return result;
    }
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

// Format BCD to decimal
int bcdToDecimal(GString *value, int flag) {
    GString *result =  g_string_new("");
    GString *trunc =  g_string_new("");
    GString *request = g_string_new("");;
    // Valid multipl to 4
    gint difference = 0;
    for (gint i = 4; i <= (value->len + 4); i += 4) {
        if (i >= (value->len - 1)) {
            difference = i - (value->len);
        }
    }

    // Add char's for complete multi the 3
    if (difference < 4 && difference != 0) {
        for (gint i = 1; i <= difference; i++) {
            g_string_prepend_c(value, '0');
        }
        g_print("mod cadena bcd: %s longi: %ld\n", value->str, value->len);
    }
    for (gint i = 4; i < (value -> len) + 4; i+=4) {
        trunc = g_string_insert(trunc, 0, value->str);
        // Recorta 3 numeros
        trunc = g_string_erase(trunc, i, 0 - 1);
        trunc = g_string_erase(trunc, 0, i - 4);
        g_print("trunc: %s\n", trunc->str);
        request = g_string_append_c(request, binToDecimal(trunc, 1));
        // g_print("i: %d  truc: %s; result = %s\n", i, trunc->str, request->str);

        // Vacia la cadena
        trunc = g_string_erase(trunc, 0, 0 - 1);
    }
    g_print("Valor: %s\n", request->str);
    if (flag == 0) {
        g_print("set Value\n");
        gtk_entry_set_text(GTK_ENTRY(txtDec), request->str);
    } else {
        int retu = 0;
        retu = atoi(request->str);
        g_print ("return: %d\n", retu);
        return retu;
    }
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
                binToDecimal(value, 0);
                DecToHexaOcta(value, 16);
                DecToHexaOcta(value, 8);
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
                    OctalToDecimal(value, 0);
                    // Decimal to hexadecimal
                    DecToHexaOctaDirect(OctalToDecimal(value, 1), 16);
                    // Decimal to binary
                    DecToHexaOctaDirect(OctalToDecimal(value, 1), 2);
                    

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
                // set base decimal 
                hexaToDec(value, 0);
                // set base octal
                DecToHexaOctaDirect(hexaToDec(value, 1), 8);
                // set base binary
                DecToHexaOctaDirect(hexaToDec(value, 1), 2);

            } else {
                sendMessage(NULL, "Numero octal no valido", "Aviso");
            }
            break;
        // Decimal to rest bases
        case 3:
            band = g_ascii_strtoll(value -> str, NULL, 0);
            if (band != 0) {
                g_print("continue\n");
                /* Convert decimal to rest bases */

                DecToHexaOctaDirect(band, 2);
                DecToHexaOctaDirect(band, 8);
                DecToHexaOctaDirect(band, 16);
            } else {
                sendMessage(NULL, "El decimal debe ser un numero diferente de 0", "Aviso");
            }
            break;
        // Format bcd
        case 4:
            // Iterat value (except char end string '\0')
            for (gint i = 0; i <= (value->len) - 1; i++) {
                // Compare chars the object string with '0', '1' y '.'
                if (!((value->str[i] == '0') || value->str[i] == '1'/* || value->str[i] == '.'*/)) {
                    flag = FALSE;
                    break;
                }
            }

            if (flag) {
                bcdToDecimal(value, 0);
                band = (gint64) bcdToDecimal(value, 1);
                g_print("Value band: %ld\n", band);
                DecToHexaOctaDirect(band, 16);
                DecToHexaOctaDirect(band, 8);
                DecToHexaOctaDirect(band, 2);
            } else {
                sendMessage(NULL, "Ingresar unicamente 0 y 1", "Aviso");
            }
            break;
        default:
            g_string_free(value, TRUE);
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
    const gchar *bcd = gtk_entry_get_text(GTK_ENTRY(txtBcd));
    
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
     if ((strcmp(bcd, "") != 0)) {
        count++;
        id = 4;
        value = bcd;
     }
    // num inputs need?
    if (count == 1) {
        GString *str = g_string_new(value);
        convert(id, str);
    } else {
        sendMessage(widget, "Solo debe ingresar un dato", "Advertencia");
    }
}
void clearEntrys() {
    if(bandCheck == 1) {
        gtk_entry_set_text(GTK_ENTRY(txtBcd), "");
        gtk_entry_set_text(GTK_ENTRY(txtBin), "");
        gtk_entry_set_text(GTK_ENTRY(txtDec), "");
        gtk_entry_set_text(GTK_ENTRY(txtHexa), "");
        gtk_entry_set_text(GTK_ENTRY(txtOcta), "");
    }
}
void clearEntrysButton(){
        gtk_entry_set_text(GTK_ENTRY(txtBcd), "");
        gtk_entry_set_text(GTK_ENTRY(txtBin), "");
        gtk_entry_set_text(GTK_ENTRY(txtDec), "");
        gtk_entry_set_text(GTK_ENTRY(txtHexa), "");
        gtk_entry_set_text(GTK_ENTRY(txtOcta), "");
}

void eventCheck() {
    if (bandCheck == 0) {
        bandCheck++;
        gtk_widget_set_visible(GTK_WIDGET(buttonClear), FALSE);
    } else {
        bandCheck--;
        gtk_widget_set_visible(GTK_WIDGET(buttonClear), TRUE);
    }
}

// Funtion construct
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *labelBin, *labelDec, *labelOcta, *labelHexa, *labelBcd;
    GtkWidget *buttonBox, *button;
    GtkWidget *check;

    // Create container
    fixed = gtk_fixed_new();

    // Create buton component
    buttonBox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    button = gtk_button_new_with_label("Calcular");
    g_signal_connect (button, "clicked", G_CALLBACK (calcular), NULL);

    buttonClearBox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    buttonClear =gtk_button_new_with_label("Limpiar entradas");
    g_signal_connect(buttonClear, "clicked", G_CALLBACK(clearEntrysButton), NULL);

    gtk_container_add(GTK_CONTAINER(buttonClearBox), buttonClear);
    gtk_container_add(GTK_CONTAINER(buttonBox), button);
    // add button and set position in fixed 
    gtk_fixed_put(GTK_FIXED(fixed), buttonBox, 270, 590);
    gtk_fixed_put(GTK_FIXED(fixed), buttonClearBox, 250, 640);

    // Create entry text with label 
    txtBin = gtk_entry_new();
    labelBin = gtk_label_new("Binario");
    g_signal_connect(txtBin, "button_press_event", G_CALLBACK(clearEntrys), NULL);
    gtk_widget_set_size_request (GTK_WIDGET(txtBin), 220, 22);

    txtOcta = gtk_entry_new();
    labelOcta = gtk_label_new("Octal");
    g_signal_connect(txtOcta, "button_press_event", G_CALLBACK(clearEntrys), NULL);
    gtk_widget_set_size_request (GTK_WIDGET(txtOcta), 220, 22);

    txtHexa = gtk_entry_new();
    labelHexa = gtk_label_new("Hexadecimal");
    g_signal_connect(txtHexa, "button_press_event", G_CALLBACK(clearEntrys), NULL);
    gtk_widget_set_size_request (GTK_WIDGET(txtHexa), 220, 22);

    txtDec = gtk_entry_new();
    labelDec = gtk_label_new("decimal");
    g_signal_connect(txtDec, "button_press_event", G_CALLBACK(clearEntrys), NULL);
    gtk_widget_set_size_request (GTK_WIDGET(txtDec), 220, 22);

    txtBcd = gtk_entry_new();
    labelBcd = gtk_label_new("Formato BCD");
    g_signal_connect(txtBcd, "button_press_event", G_CALLBACK(clearEntrys), NULL);
    gtk_widget_set_size_request (GTK_WIDGET(txtBcd), 220, 22);

    // Add witgets at fixed with position
    gtk_fixed_put(GTK_FIXED(fixed), txtBin, 220, 100);
    gtk_fixed_put(GTK_FIXED(fixed), txtOcta, 220, 200);
    gtk_fixed_put(GTK_FIXED(fixed), txtDec, 220, 300);
    gtk_fixed_put(GTK_FIXED(fixed), txtHexa, 220, 400);
    gtk_fixed_put(GTK_FIXED(fixed), txtBcd, 220, 500);

    gtk_fixed_put(GTK_FIXED(fixed), labelBin, 220, 85);
    gtk_fixed_put(GTK_FIXED(fixed), labelOcta, 220, 185);
    gtk_fixed_put(GTK_FIXED(fixed), labelDec, 220, 285);
    gtk_fixed_put(GTK_FIXED(fixed), labelHexa, 220, 385);
    gtk_fixed_put(GTK_FIXED(fixed), labelBcd, 220, 485);

    // Check clear onclick
    check = gtk_check_button_new_with_label("Limpiar con un click");
    g_signal_connect(check, "clicked", G_CALLBACK(eventCheck), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), check, 220, 535);

    // Create window aplication
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Converidor de bases");
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