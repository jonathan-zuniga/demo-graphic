#include "bsgMenagerie.h"

namespace bsg {
  
  drawableRectangle::drawableRectangle(bsgPtr<shaderMgr> pShader,
                                       const float width, const float height) :
    drawableCompound(pShader), _height(height), _width(width) {

    std::vector<glm::vec4> frontFaceVertices;

    frontFaceVertices.push_back(glm::vec4( 0.0f, 0.0f, 0.0f, 1.0f));
    frontFaceVertices.push_back(glm::vec4( _width, 0.0f, 0.0f, 1.0f));
    frontFaceVertices.push_back(glm::vec4( 0.0f, _height, 0.0f, 1.0f));
    frontFaceVertices.push_back(glm::vec4( _width, _height, 0.0f, 1.0f));

    _frontFace.addData(bsg::GLDATA_VERTICES, "position", frontFaceVertices);

    // Here are the corresponding colors for the above vertices.
    std::vector<glm::vec4> frontFaceColors;
    frontFaceColors.push_back(glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f));
    frontFaceColors.push_back(glm::vec4( 1.0f, 0.0f, 0.0f, 1.0f));
    frontFaceColors.push_back(glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f));
    frontFaceColors.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));

    _frontFace.addData(bsg::GLDATA_COLORS, "color", frontFaceColors);

    std::vector<glm::vec4> frontFaceNormals;

    frontFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));
    frontFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));
    frontFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));
    frontFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));

    _frontFace.addData(bsg::GLDATA_NORMALS, "normal", frontFaceNormals);

    std::vector<glm::vec2> frontFaceUVs;

    frontFaceUVs.push_back(glm::vec2( 0.0f, 0.0f));
    frontFaceUVs.push_back(glm::vec2( 1.0f, 0.0f));
    frontFaceUVs.push_back(glm::vec2( 0.0f, 1.0f));
    frontFaceUVs.push_back(glm::vec2( 1.0f, 1.0f));

    _frontFace.addData(bsg::GLDATA_UVS, "texture", frontFaceUVs);
    
    // The vertices above are arranged into a set of triangles.
    _frontFace.setDrawType(GL_TRIANGLE_STRIP);  

    // Same thing for the other rectangle.
    std::vector<glm::vec4> backFaceVertices;

    backFaceVertices.push_back(glm::vec4( 0.0f, 0.0f, 0.0f, 1.0f));
    backFaceVertices.push_back(glm::vec4( 0.0f, _height, 0.0f, 1.0f));
    backFaceVertices.push_back(glm::vec4( _width, 0.0f, 0.0f, 1.0f));
    backFaceVertices.push_back(glm::vec4( _width, _height, 0.0f, 1.0f));

    _backFace.addData(bsg::GLDATA_VERTICES, "position", backFaceVertices);

    // And the corresponding colors for the above vertices.
    std::vector<glm::vec4> backFaceColors;
    backFaceColors.push_back(glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f));
    backFaceColors.push_back(glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f));
    backFaceColors.push_back(glm::vec4( 1.0f, 0.0f, 0.0f, 1.0f));
    backFaceColors.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));

    _backFace.addData(bsg::GLDATA_COLORS, "color", backFaceColors);

    std::vector<glm::vec4> backFaceNormals;

    backFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));
    backFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));
    backFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));
    backFaceNormals.push_back(glm::vec4( 0.0f, 0.0f, 1.0f, 1.0f));

    _backFace.addData(bsg::GLDATA_NORMALS, "normal", backFaceNormals);

    std::vector<glm::vec2> backFaceUVs;

    backFaceUVs.push_back(glm::vec2( 0.0f, 0.0f));
    backFaceUVs.push_back(glm::vec2( 0.0f, 1.0f));
    backFaceUVs.push_back(glm::vec2( 0.0f, 1.0f));
    backFaceUVs.push_back(glm::vec2( 1.0f, 1.0f));

    _backFace.addData(bsg::GLDATA_UVS, "texture", backFaceUVs);
    
    // The vertices above are arranged into a set of triangles.
    _backFace.setDrawType(GL_TRIANGLE_STRIP);  

    addObject(_frontFace);
    addObject(_backFace);
  }

}
