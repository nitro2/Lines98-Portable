#ifndef  _MAP_HPP_
#define _MAP_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    TileMap(sf::Vector2f position, int row_lines, int col_lines, float distance);
    ~TileMap();

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // std::cout << typeid(this).name() << "-" << __FUNCTION__ << " " << __LINE__ << std::endl;
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

#endif /* _MAP_HPP_ */