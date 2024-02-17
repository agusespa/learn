#import "Textbox.h"

Textbox::Textbox(sf::Vector2u l_wind_size) {
    m_width = 200;
    m_num_visible = 5;

    font.loadFromFile("assets/joystix.otf");
    m_content.setFont(font);

    m_content.setString("");
    m_content.setCharacterSize(60);
    m_content.setFillColor(sf::Color::White);

    m_backdrop.setSize(sf::Vector2f(l_wind_size.x, l_wind_size.y));
    m_backdrop.setFillColor(sf::Color(90, 90, 90, 200));
}

Textbox::~Textbox() {}

void Textbox::AddMessage(std::string l_message) { m_message = l_message; }

void Textbox::Render(sf::RenderWindow& l_wind, sf::Vector2u l_wind_size) {
    std::string l_content;
    if (m_message != "") {
        m_content.setString(m_message);
        m_content.setOrigin(m_content.getLocalBounds().width / 2,
                            m_content.getLocalBounds().height / 2);

        m_content.setPosition(l_wind_size.x / 2.0f, l_wind_size.y / 2.0f);

        l_wind.draw(m_backdrop);
        l_wind.draw(m_content);
    }
}
