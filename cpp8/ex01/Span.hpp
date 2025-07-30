
#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
  private:
    unsigned int _length;
    

  public:
    Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    
    void addNumber();

};

#endif