/*
 * Copyright (c) 2020, Matthew Olsson <matthewcolsson@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <AK/FlyString.h>
#include <LibWeb/DOM/SvgContext.h>

namespace Web {

void SvgGraphicElement::parse_attribute(const FlyString& name, const String& value)
{
    if (name == "stroke-width") {
        m_stroke_width = strtof(value.characters(), nullptr);
    } else if (name == "stroke") {
        auto result = Gfx::Color::from_string(value);
        m_stroke_color = result.value_or(Gfx::Color::Transparent);
    } else if (name == "fill") {
        auto result = Gfx::Color::from_string(value);
        m_fill_color = result.value_or(Gfx::Color::Transparent);
    }
}

Gfx::Color SvgGraphicElement::fill_color(const SvgPaintingContext& context) const
{
    return m_fill_color.value_or(context.fill_color);
}

Gfx::Color SvgGraphicElement::stroke_color(const SvgPaintingContext& context) const
{
    return m_stroke_color.value_or(context.stroke_color);
}

float SvgGraphicElement::stroke_width(const SvgPaintingContext& context) const
{
    return m_stroke_width.value_or(context.stroke_width);
}

}