#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO;

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); //������� ������ ����� ������� ������ ������� 

    glEnableVertexAttribArray(0); //��������� ������� ��������� ������ � �������� 0
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //���������� ������ ������ � ��������������� VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // �� ��� ������� ����� ������������ ������ ������ ������

    glColor3f(0.0f, 0.0f, 1.0f); //���� ������������
    glDrawArrays(GL_TRIANGLES, 0, 3);  //����� ������, � �������� ���������� ������

    glDisableVertexAttribArray(0); //����������� ������� ��������� ������ � �������� 0

    glutSwapBuffers(); //����� ������� � ����������� �� ������
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB); // ����� �� ���� �������������� � ������� �������� 
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[3];//������� ������ ������������
    Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f); //�����
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f); //������
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f); //�������

    glGenBuffers(1, &VBO); // �������� ������� ������
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // ���������� ������
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // ������ ������ ������ � ������
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); // ������������� GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // ������� ����������� � ������ �����
    glutInitWindowSize(1024, 768); //������ ���� 
    glutInitWindowPosition(100, 100); //������� ����
    glutCreateWindow("Gainetdinov Lab1"); //�������� ����

    InitializeGlutCallbacks();

    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    } // �������������� GLEW � ��������� �� ������

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //���� ���� � ������� ARGB

    CreateVertexBuffer();

    glutMainLoop();

    return 0;
}

