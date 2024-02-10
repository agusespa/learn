#include "Window.h"

#include <SFML/Graphics.hpp>

using namespace std;

Window::Window(const string& l_title, const sf::Vector2u& l_size) {
    Setup(l_title, l_size);
}

Window::~Window() { Destroy(); }

void Window::Setup(const string& l_title, const sf::Vector2u& l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isDone = false;
    Create();
}

void Window::Create() {
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle,
                    sf::Style::Close | sf::Style::Titlebar);
}

void Window::Update() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_isDone = true;
        }
    }
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }
void Window::EndDraw() { m_window.display(); }

bool Window::IsDone() { return m_isDone; }

sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::Destroy() { m_window.close(); }
