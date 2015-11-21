//Sofia & Patrik
#ifndef FIGURES_H
#define FIGURES_H
#include "Figure.h"

class I final : public Figure
{
    public:
        I()
        : Figure() {}
        virtual ~I();
        void rotate() override;
    protected:
    private:
};

class J final : public Figure
{
    public:
        J()
        : Figure() {}
        virtual ~J();
        void rotate()  override;
    protected:
    private:
};

class L final : public Figure
{
    public:
        L()
        : Figure() {}
        virtual ~L();
        void rotate() override;
    protected:
    private:
};

class O final : public Figure
{
    public:
        O()
        : Figure() {}
        virtual ~O();
        void rotate() override;
    protected:
    private:
};

class T final : public Figure
{
    public:
        T()
        : Figure() {}
        virtual ~T();
        void rotate() override;
    protected:
    private:
};

class S final : public Figure
{
    public:
        S()
        : Figure() {}
        virtual ~S();
        void rotate() override;
    protected:
    private:
};

class Z final : public Figure
{
    public:
        Z()
        : Figure() {}
        virtual ~Z();
        void rotate() override;
    protected:
    private:
};

#endif // FIGURES_H
