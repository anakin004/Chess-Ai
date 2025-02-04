#include"VBO.h"
#include <vector>


VBO::VBO(std::vector<Vertex>& vertices)
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}


void VBO::LoadBuffer(std::vector<Vertex>& vertices, GLuint numVerts)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	GlCall(glBufferData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * numVerts, &vertices));
}


VBO::~VBO()
{
	glDeleteBuffers(1, &m_ID);
}

void VBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VBO::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
