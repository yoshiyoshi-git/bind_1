#pragma once

#include "StringVecViewModel.g.h"
#include "StringViewModel.h"

namespace winrt::bind_1::implementation
{
    struct StringVecViewModel : StringVecViewModelT<StringVecViewModel>
    {
        StringVecViewModel();

        bind_1::StringViewModel StringViewModel();
        Windows::Foundation::Collections::IObservableVector<bind_1::StringViewModel> SVModelVec();

    private:
        bind_1::StringViewModel m_SVModel{ nullptr };
        Windows::Foundation::Collections::IObservableVector<bind_1::StringViewModel> m_SVModelVec{ nullptr };

    };
}

namespace winrt::bind_1::factory_implementation
{
    struct StringVecViewModel : StringVecViewModelT<StringVecViewModel, implementation::StringVecViewModel>
    {
    };
}
