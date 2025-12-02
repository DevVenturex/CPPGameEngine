#pragma once

#include <any>
#include <stdexcept>
#include <string>

class ResultException final : public std::runtime_error
{
public:
    explicit ResultException(const std::string& msg) : std::runtime_error(msg) 
    {}
};

template <typename T, typename E = std::string>
class Result
{
public:
    static Result Ok(T value)
    {
        Result result;
        result.ok_ = std::move(value);
        return result;
    }

    static Result Err(E error)
    {
        Result result;
        result.err_ = std::move(error);
        return result;
    }

    [[nodiscard]] bool is_ok() const { return ok_.has_value(); }

    [[nodiscard]] bool is_err() const { return err_.has_value(); }

    T unwrap() const
    {
        if (is_err())
        {
            throw ResultException("Unwrapped an Err value");
        }
        return std::any_cast<T>(ok_);
    }

    E unwrap_err() const
    {
        if (is_ok())
        {
            throw ResultException("Unwrapped_err on an ok value");
        }
        return std::any_cast<E>(err_);
    }

    T unwrap_or(T default_value) const
    {
        return is_ok() ? std::any_cast<T>(ok_) : default_value;
    }

    template <typename OkFunc, typename ErrFunc>
    auto match(OkFunc ok_func, ErrFunc err_func) const 
    {
        if (is_ok())
        {
            return ok_func(std::any_cast<T>(ok_));
        }
        else
        {
            return err_func(std::any_cast<E>(err_));
        }
    }

private:
    std::any ok_;
    std::any err_;
};