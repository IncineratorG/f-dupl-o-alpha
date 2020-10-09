#ifndef STATEPROPLIKE_H
#define STATEPROPLIKE_H


class StatePropLike
{
public:
    StatePropLike();
    virtual ~StatePropLike();

    void setPropId(const int id);
    void setUpdated(const bool updated);

    int propId() const;
    bool updated() const;

private:
    int mPropId;
    bool mUpdated;
};

#endif // STATEPROPLIKE_H
