#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO;

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); //Очистка буфера цвета текущим цветом очистки 

    glEnableVertexAttribArray(0); //активация массива атрибутов вершин с индексом 0
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //связывание буфера вершин с идентификатором VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // то как конвеер будет воспринимать данные внутри буфера

    glColor3f(0.0f, 0.0f, 1.0f); //цвет треугольника
    glDrawArrays(GL_TRIANGLES, 0, 3);  //Выбор фигуры, и указание количества вершин

    glDisableVertexAttribArray(0); //деактивация массива атрибутов вершин с индексом 0

    glutSwapBuffers(); //смена буферов и отображение на экране
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB); // берет на себя взаимодействие с оконной системой 
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[3];//Матрица вершин треугольника
    Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f); //Левый
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f); //Правый
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f); //Верхний

    glGenBuffers(1, &VBO); // Создание объекта буфера
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Связывание буфера
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // запись данных вершин в буффер
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Двойная буферизация и буфера цвета
    glutInitWindowSize(1024, 768); //размер окна 
    glutInitWindowPosition(100, 100); //позиция окна
    glutCreateWindow("Gainetdinov Lab1"); //название окна

    InitializeGlutCallbacks();

    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    } // инициализирует GLEW и проверяет на ошибки

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Цвет фона в формате ARGB

    CreateVertexBuffer();

    glutMainLoop();

    return 0;
}

