#ifndef DELEGATE_HPP_
#define DELEGATE_HPP_

//--------------------------------------------------------------------------------------------------------
// This class is responsible to define an "invoke" operation to a future delegate instance.
//--------------------------------------------------------------------------------------------------------
class DelegateBooleanParameter
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Virtual destructor to safely inherit.
	virtual ~DelegateBooleanParameter(){}
	//--------------------------------------------------------------------------------------------------------
	//! \pre "newState" should be understandable by the methods to call
	//! \post None
	virtual void Invoke(bool newState)= 0;
};

//--------------------------------------------------------------------------------------------------------
// This delegate class is responsible to stock a instance reference and a method to call on this reference
// With these two references, the invoke() operation should call properly a method without knowing the
// exact object.
// warning : the signature of the method is void method(bool newState)
//--------------------------------------------------------------------------------------------------------
template <typename T>
class TypedDelegateBooleanParameter : public DelegateBooleanParameter
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre See parent
	//! \post See parent
	virtual void Invoke(bool newState);

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'instance' and 'functionPointer' references should be thread safe !
	//!	'functionPoiner' method has to be thread safe.
	TypedDelegateBooleanParameter<T>(T &instance, void (T::*functionPointer)(bool));

	//--------------------------------------------------------------------------------------------------------
	//! \pre See parent
	//! \post See parent
	~TypedDelegateBooleanParameter<T>(){}

private:
	//instance from where we will call the handler
	T &_instance;
	// function pointer to a method from type pointed by 'm_instance'
	void (T::*_functionPointerToInstance)(bool);

};

//--------------------------------------------------------------------------------------------------------
template<typename T>
TypedDelegateBooleanParameter<T>::TypedDelegateBooleanParameter( T &instance,void (T::*functionPointer)(bool)):
_instance(instance),
_functionPointerToInstance(functionPointer)
{
}

//--------------------------------------------------------------------------------------------------------
template<typename T>
void TypedDelegateBooleanParameter<T>::Invoke(bool newState)
{
	//we invoke the handler onto instance
	((_instance).*(_functionPointerToInstance))(newState);
}

#endif /* DELEGATE_HPP_ */
