#pragma once

#include <string>


// static화 하는 방법도 있을까?


class Product
{
    private:
        std::string     data;
    
    public:
        void    setPart1()
        {
            this->data.append("Part1");
        };

        void    setPart2()
        {
            this->data.append("Part2");
        };

        void    setPart3()
        {
            this->data.append("Part3");
        };

        void    reset()
        {
            this->data.clear();  
        };

        std::string&    getData()
        {
            return (this->data);
        }

        Product()
        {

        };

        ~Product()
        {

        };

        Product(const Product &cp)
        {
            this->data = cp.data;
        };

        Product&    operator=(const Product &cp)
        {
            this->data = cp.data;
            return (*this);
        };


};


// Builder의 추상 클래스 - 다형성, 최소 요건 설정 등
class IBuilder
{
    private:


    public:
        virtual ~IBuilder() {};
        virtual void    reset() = 0;
        virtual void    build_part1() = 0;
        virtual void    build_part2() = 0;
        virtual void    build_part3() = 0;
        virtual Product*    getResult() = 0;
};

class BuilderA : public IBuilder
{
    private:
        Product*     build_objectA;

        void    reset()
        {
            this->build_objectA->reset();
        };

        void    build_part1()
        {
            this->build_objectA->setPart1();
        };

        void    build_part2()
        {
            this->build_objectA->setPart2();
        };
        
        void    build_part3()
        {
            this->build_objectA->setPart3();
        };

        // void    result();
        
        Product* getResult()
        {
            return (new Product(*this->build_objectA));
        };

    public:
        BuilderA()
        {
            this->build_objectA = new Product();
        };

        ~BuilderA()
        {
            delete this->build_objectA;
        };
};

class BuilderB : public IBuilder
{
    private:
        Product*     build_objectB;

        void    reset()
        {
            this->build_objectB->reset();
        };

        void    build_part1()
        {
            this->build_objectB->setPart3();
        };

        void    build_part2()
        {

            this->build_objectB->setPart1();
        };
        
        void    build_part3()
        {

            this->build_objectB->setPart2();
        };

        // void    result();
        
        Product* getResult()
        {
            return (new Product(*this->build_objectB));
        };

    public:
        BuilderB()
        {
            this->build_objectB = new Product();
        };

        ~BuilderB()
        {
            delete this->build_objectB;
        };
};

// builder 설정 위한 클래스. Builder만 가지고도 사용은 가능함.
    // 하지만 Builder 과정의 Encapsulation, Build 사용 간편화 가능.
class Director
{
    private:
        IBuilder*    now_builder;
    
    public:
        Director(IBuilder* new_builder)
        {
            this->now_builder = new_builder;
        };

        ~Director()
        {
            // builder를 밖에서 받아와서 만드니, 수명 관리 책임을 바깥에 두는게 나은가?
            // delete this->now_builder;
        };

        void changeBuilder(IBuilder* new_builder)
        {
            this->now_builder = new_builder;
        };
        // builder의 동작 구성 자체도 동적으로 받나?
            // 아니면 특정 조합을 저장하는게 맞나?
        Product*    doPart1Part2Part3()
        {
            this->now_builder->reset();
            this->now_builder->build_part1();
            this->now_builder->build_part2();
            this->now_builder->build_part3();
            return (this->now_builder->getResult());
        };

        Product*    doPart1Part3()
        {
            this->now_builder->reset();
            this->now_builder->build_part1();
            this->now_builder->build_part3();
            return (this->now_builder->getResult());
        };

        Product*    doPart2()
        {
            this->now_builder->reset();
            this->now_builder->build_part2();
            return (this->now_builder->getResult());
        };
};
