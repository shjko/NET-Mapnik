#pragma once

#include <mapnik\layer.hpp>
#include <boost\shared_ptr.hpp>

namespace NETMapnik
{
	typedef boost::shared_ptr<mapnik::layer> layer_ptr;

	public ref class Layer
	{
	public:
		Layer(System::String^ name);
		Layer(System::String^ name, System::String^ srs);
		~Layer();

		property System::String^ Name
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property System::String^ SRS
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property System::Collections::Generic::IEnumerable<System::String^>^ Styles
		{
			System::Collections::Generic::IEnumerable<System::String^>^ get();
			void set(System::Collections::Generic::IEnumerable<System::String^>^ value);
		}

		//property Datasource
		//{
		//	Datasource^ get();
		//	void set(Datasource^ value);
		//}

		System::Collections::Generic::Dictionary<System::String^, System::Object^>^ Describe();

	internal:
		Layer(mapnik::layer const &layer);
		layer_ptr NativeObject();

	private:
		layer_ptr *_layer;
	};
}