#include "pch.h"
#include "StringVecViewModel.h"
#if __has_include("StringVecViewModel.g.cpp")
#include "StringVecViewModel.g.cpp"
#endif

namespace winrt::bind_1::implementation
{
    StringVecViewModel::StringVecViewModel()
    {
        m_SVModel = winrt::make<bind_1::implementation::StringViewModel>();

        m_SVModelVec = winrt::single_threaded_observable_vector<bind_1::StringViewModel>();
        m_SVModelVec.Append(m_SVModel);
    }

    bind_1::StringViewModel StringVecViewModel::StringViewModel()
    {
        return m_SVModel;
    }

    Windows::Foundation::Collections::IObservableVector<bind_1::StringViewModel> StringVecViewModel::SVModelVec()
    {
        return m_SVModelVec;
    }
}
