//*****************************************************************************
// Copyright 2017-2021 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#include <memory>

#include "ngraph/shape.hpp"
#include "ngraph/validation_util.hpp"
#include "onnx_import/default_opset.hpp"
#include "onnx_import/exceptions.hpp"
#include "onnx_import/op/unsqueeze.hpp"

namespace ngraph
{
    namespace onnx_import
    {
        namespace op
        {
            namespace set_1
            {
                OutputVector unsqueeze(const Node& node)
                {
                    auto data = node.get_ng_inputs().at(0);
                    auto axes = node.get_attribute_value<std::vector<std::int64_t>>("axes", {});
                    auto axes_node = std::make_shared<default_opset::Constant>(
                        element::i64, Shape{axes.size()}, axes);
                    return {std::make_shared<default_opset::Unsqueeze>(data, axes_node)};
                }

            } // namespace set_1

            namespace set_13
            {
                OutputVector unsqueeze(const Node& node)
                {
                    auto inputs = node.get_ng_inputs();
                    return {std::make_shared<default_opset::Unsqueeze>(inputs.at(0), inputs.at(1))};
                }

            } // namespace set_13
        }     // namespace op

    } // namespace onnx_import

} // namespace ngraph
