#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Label label_firstname;
    Gtk::Entry entry_firstname;
    Gtk::Label label_lastname;
    Gtk::Entry entry_lastname;
    Gtk::Button button;
    Gtk::Label label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        set_title("Øving 4 Oppgave 2");

        label_firstname.set_text("First name:"); // Set text of label
        label_lastname.set_text("Last name:"); // Set text of entry
        button.set_label("Combine names:"); // Set text of button
        button.set_sensitive(false);

        box.pack_start(label_firstname); // Add the widget label to box
        box.pack_start(entry_firstname);  // Add the widget entry to box
        box.pack_start(label_lastname);  // Add the widget label to box
        box.pack_start(entry_lastname);   // Add the widget entry to box
        box.pack_start(button); // Add the widget button to box
        box.pack_start(label);  // Add the widget label to box

        add(box);   // Add vbox to window
        show_all(); // Show all widgets

        // If the text in the entry fields are not empty, the button will be enabled
        entry_firstname.signal_changed().connect([this]() {
            if (!entry_firstname.get_text().empty() && !entry_lastname.get_text().empty()) {
                button.set_sensitive(true);
            } else {
                button.set_sensitive(false);
            }
        });

        // If the text in the entry fields are not empty, the button will be enabled
        entry_lastname.signal_changed().connect([this]() {
            if (!entry_firstname.get_text().empty() && !entry_lastname.get_text().empty()) {
                button.set_sensitive(true);
            } else {
                button.set_sensitive(false);
            }
        });

        // When the button is clicked, the text in the label will be set to the text in the entry fields
        button.signal_clicked().connect([this]() {
            label.set_text(entry_firstname.get_text() + " " + entry_lastname.get_text());
        });


    }
};

// Create the application and run the window
int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}