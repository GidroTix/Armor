#ifndef PatternsH
#define PatternsH

template<class Type>
class Iterator
{
protected:
    Iterator() {}

public:
    virtual ~Iterator() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Type GetNumber() const = 0;
};

template<class Type>
class IteratorDecorator : public Iterator<Type>
{
protected:
    Iterator<Type> *It;

public:
    IteratorDecorator(Iterator<Type> *it)
    {
        It = it;
    }

    virtual~IteratorDecorator() { delete It; }
    virtual void First() { It->First(); }
    virtual void Next() { It->Next(); }
    virtual bool IsDone() const { return It->IsDone(); }
    virtual Type GetNumber() const { return It->GetNumber(); }
};
#endif // PatternsH
