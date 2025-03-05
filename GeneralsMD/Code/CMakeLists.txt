
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
cmake_minimum_required(VERSION 3.10)  # Use a lower version since 3.30 is too new
project(GeneralsZH-AllStars)

# Directories for game components
add_subdirectory(GameEngine)
add_subdirectory(GameEngineDevice)
add_subdirectory(Dep)
add_subdirectory(Lib)
add_subdirectory(Tools)
add_subdirectory(Main)


target_include_directories(GeneralsZH-AllStars PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Dep/DX90SDK/Include
)