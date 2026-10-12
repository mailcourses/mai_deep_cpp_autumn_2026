module;


export module mexample;

export struct Foo;

int nonexported_square(int num)
{
    return num * num;
}

export int msquare(int num)
{
    return nonexported_square(num);
}

export
{
    int a = 10;
}

export namespace dzen
{
    int a = 10;
}

struct Foo
{
    int sum()
    {
        return 100500;
    }
};
