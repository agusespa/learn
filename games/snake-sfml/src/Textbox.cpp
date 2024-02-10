#import "Textbox.h"

Textbox::Textbox(sf::Vector2u l_windSize) {
    m_width = 200;
    m_numVisible = 5;

    font.loadFromFile("assets/FunSnake.otf");
    m_content.setFont(font);

    m_content.setString("");
    m_content.setCharacterSize(60);
    m_content.setFillColor(sf::Color::White);

    m_backdrop.setSize(sf::Vector2f(l_windSize.x, l_windSize.y));
    m_backdrop.setFillColor(sf::Color(90, 90, 90, 90));
}

Textbox::~Textbox() {}

void Textbox::AddMessage(std::string l_message) { m_message = l_message; }

void Textbox::Render(sf::RenderWindow& l_wind, sf::Vector2u l_windSize) {
    std::string l_content;
    if (m_message != "") {
        m_content.setString(m_message);
        m_content.setOrigin(m_content.getLocalBounds().width / 2,
                            m_content.getLocalBounds().height / 2);

        m_content.setPosition(l_windSize.x / 2, l_windSize.y / 2);

        l_wind.draw(m_backdrop);
        l_wind.draw(m_content);
    }
}
