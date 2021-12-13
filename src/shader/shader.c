#include "shader.h"

void shaderInit(struct Shader* shader, char* vertexFilepath, char* fragmentFilepath) {
    char* buffer; 
    long lSize;
    
    FILE* vertexFile = fopen(vertexFilepath, "r");
    if (!vertexFile) perror(vertexFilepath), exit(1);
    
    fseek(vertexFile, 0L, SEEK_END);
    lSize = ftell(vertexFile);
    rewind(vertexFile);
    
    /* Allocate memory for entire context */
    
    buffer = calloc(1, lSize + 1);
    if (!buffer) fclose(vertexFile), fputs("ERROR::MEMORY::ALLOCATION::FAILURE", stderr), exit(1);
    
    /* Copy file into buffer */
    if (1!=fread(buffer, lSize, 1, vertexFile)) {
        fclose(vertexFile), free(buffer), fputs("ERROR::FILE::READ::FAILURE", stderr), exit(1);
    }
    
    shader->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader->vertexShader, 1, (const char*)&buffer, NULL);
    glCompileShader(shader->vertexShader);
    
    int success;
    char infoLog[512];
    glGetShaderiv(shader->vertexShader, GL_COMPILE_STATUS, &success);
    
    if (!success) {
        glGetShaderInfoLog(shader->vertexShader, 512, NULL, infoLog);
        free(buffer);
        printf("%s\n", "ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        fputs(infoLog, stderr);
        exit(1);
    }
    
    fclose(vertexFile);
    shader->vertexShaderPath = vertexFilepath;
    
    free(buffer);
    
    FILE* fragmentFile;
    fragmentFile = fopen(fragmentFilepath, "r");
    
    if (!fragmentFile) perror(fragmentFilepath), exit(1);
    
    fseek(fragmentFile, 0L, SEEK_END);
    lSize = ftell(fragmentFile);
    rewind(fragmentFile);
    
    buffer = calloc(1, lSize + 1);
    if (!buffer) fclose(fragmentFile), fputs("ERROR::MEMORY::ALLOCATION::FAILURE", stderr), free(buffer), exit(1);
    
    if (1!=fread(buffer, lSize, 1, fragmentFile)) {
        fclose(fragmentFile), free(buffer), fputs("ERROR::FILE::READ::FAILURE", stderr), exit(1);
    }
    
    fclose(fragmentFile);
    shader->fragmentShaderPath = fragmentFilepath;
    
    shader->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader->fragmentShader, 1, (const char*)&buffer, NULL);
    glCompileShader(shader->fragmentShader);
    
    glGetShaderiv(shader->fragmentShader, GL_COMPILE_STATUS, &success);
    
    
    if (!success) {
        glGetShaderInfoLog(shader->fragmentShader, 512, NULL, infoLog);
        free(buffer);
        printf("%s\n", "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
        fputs(infoLog, stderr);
        exit(1);
    }
    
    shader->shaderID = glCreateProgram();
    
    glAttachShader(shader->shaderID, shader->vertexShader);
    glAttachShader(shader->shaderID, shader->fragmentShader);
    glLinkProgram(shader->shaderID);
    
    glGetProgramiv(shader->shaderID, GL_LINK_STATUS, &success);
    
    if (!success) {
        glGetProgramInfoLog(shader->shaderID, 512, NULL, infoLog);
        printf("%s\n", "ERROR::SHADER::PROGRAM::LINKING_FAILED");
        fputs(infoLog, stderr);
        exit(1);
    }
    
    glDeleteShader(shader->vertexShader);
    glDeleteShader(shader->fragmentShader);
    
    free(buffer);
}

void useShader(struct Shader* shader) {
    if (!shader->beingUsed) {
       glUseProgram(shader->shaderID);
       shader->beingUsed = 1;
    }
}

void detachShader(struct Shader* shader) {
    glUseProgram(0);
    shader->beingUsed = 0;
}

void sentInt2Shader(struct Shader shader, const char* varName, int val);
void sendFloat2Shader(struct Shader shader, const char* varName, float val);

void sendMat42Shader(struct Shader* shader, const char* varName, mat4 val) {
    useShader(shader);
    glUniformMatrix4fv(glGetUniformLocation(shader->shaderID, varName), 1, GL_FALSE, (float*)val);
    detachShader(shader);
}

