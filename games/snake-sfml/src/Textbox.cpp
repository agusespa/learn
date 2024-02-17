#import "Textbox.h"

Textbox::Textbox(sf::Vector2u window_size) {
    width = 200;
    num_visible = 5;

    font.loadFromFile("assets/FunSnake.otf");
    content.setFont(font);

    content.setString("");
    content.setCharacterSize(60);
    content.setFillColor(sf::Color::White);

    backdrop.setSize(sf::Vector2f(window_size.x, window_size.y));
    backdrop.setFillColor(sf::Color(90, 90, 90, 200));
}

Textbox::~Textbox() {}

void Textbox::AddMessage(std::string message) { message = message; }

void Textbox::Render(sf::RenderWindow& window, sf::Vector2u window_size) {
    if (message != "") {
        content.setString(message);
        content.setOrigin(content.getLocalBounds().width / 2,
                          content.getLocalBounds().height / 2);

        content.setPosition(window_size.x / 2.0f, window_size.y / 2.0f);

        window.draw(backdrop);
        window.draw(content);
    }
}
