#include "Window.h"

#include <SFML/Graphics.hpp>

using namespace std;

Window::Window(const string& l_title, const sf::Vector2u& l_size) {
    m_window_title = l_title;
    m_window_size = l_size;
    m_is_done = false;
    m_window.create({m_window_size.x, m_window_size.y, 32}, m_window_title,
                    sf::Style::Close | sf::Style::Titlebar);
}

Window::~Window() { m_window.close(); }

void Window::Update() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_is_done = true;
        }
    }
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }
void Window::EndDraw() { m_window.display(); }

bool Window::IsDone() { return m_is_done; }

sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }
sf::Vector2u Window::GetWindowSize() { return m_window_size; }
