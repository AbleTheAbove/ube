const std = @import("std");
const meta = std.meta;
// const math = @import("math");
const math = @import("../math/lib.zig");

pub fn Uniform(comptime T : type) type {
    return struct {
      
        pub const Element = T;

        location : u32 = 0,
        program : c_uint = 0,

        const Self = @This();

        const self_info = uniformInfo(Self);

        pub usingnamespace switch(self_info.element_info.kind) {
            .single => |single| struct {

                pub fn set(self : Self, value : Element) void {
                    switch (single) {
                        .primitive => |primitive| {
                            switch (primitive) {
                                i32 => {
                                    std.log.debug("glProgramUniform1i(self.program, self.location, value)", .{});
                                },
                                u32 => {
                                    std.log.debug("glProgramUniform1ui(self.program, self.location, value)", .{});
                                },
                                f32 => {
                                    std.log.debug("glProgramUniform1f(self.program, self.location, value)", .{});
                                },
                                else => unreachable,
                            }
                        },
                        .vector => |vector| {
                            switch (vector.Element) {
                                i32 => {
                                    switch (vector.dimensions) {
                                        2 => std.log.debug("glProgramUniform2i(self.program, self.location, value.x, value.y", .{}),
                                        3 => std.log.debug("glProgramUniform3i(self.program, self.location, value.x, value.y, value.z", .{}),
                                        4 => std.log.debug("glProgramUniform4i(self.program, self.location, value.x, value.y, value.z, value.w", .{}),
                                        else => unreachable,
                                    }
                                },
                                u32 => {
                                    switch (vector.dimensions) {
                                        2 => std.log.debug("glProgramUniform2ui(self.program, self.location, value.x, value.y", .{}),
                                        3 => std.log.debug("glProgramUniform3ui(self.program, self.location, value.x, value.y, value.z", .{}),
                                        4 => std.log.debug("glProgramUniform4ui(self.program, self.location, value.x, value.y, value.z, value.w", .{}),
                                        else => unreachable,
                                    }
                                },
                                f32 => {
                                    switch (vector.dimensions) {
                                        2 => std.log.debug("glProgramUniform2f(self.program, self.location, value.x, value.y", .{}),
                                        3 => std.log.debug("glProgramUniform3f(self.program, self.location, value.x, value.y, value.z", .{}),
                                        4 => std.log.debug("glProgramUniform4f(self.program, self.location, value.x, value.y, value.z, value.w", .{}),
                                        else => unreachable,
                                    }
                                },
                                else => unreachable,
                            }
                        },
                        .matrix => |matrix| {
                            const transpose = false;
                            switch (matrix.row_count) { // we dont need to worry about col_count because we know its square
                                2 => std.log.debug("glProgramUniformMatrix2fv(self.program, self.location, 1, transpose, &value.field[0][0])", .{}),
                                3 => std.log.debug("glProgramUniformMatrix3fv(self.program, self.location, 1, transpose, &value.field[0][0])", .{}),
                                4 => std.log.debug("glProgramUniformMatrix4fv(self.program, self.location, 1, transpose, &value.field[0][0])", .{}),
                                else => unreachable,
                            }
                        },
                    }
                }

            },
            .array => |array| struct {

                pub fn set(self : Self, value : [] const array.Child) void {
                    switch (array.element_kind) {
                        .primitive => |primitive| {
                            switch (primitive) {
                                i32 => {
                                    std.log.debug("glProgramUniform1iv(self.program, self.location, value.len value.ptr)", .{});
                                },
                                u32 => {
                                    std.log.debug("glProgramUniform1uiv(self.program, self.location, value.len value.ptr)", .{});
                                },
                                f32 => {
                                    std.log.debug("glProgramUniform1fv(self.program, self.location, value.len value.ptr)", .{});
                                },
                                else => unreachable,
                            }
                        },
                        .vector => |vector| {
                            switch (vector.Element) {
                                i32 => {
                                    switch (vector.dimensions) {
                                        2 => std.log.debug("glProgramUniform2iv(self.program, self.location, value.len, value.ptr", .{}),
                                        3 => std.log.debug("glProgramUniform3iv(self.program, self.location, value.len, value.ptr", .{}),
                                        4 => std.log.debug("glProgramUniform4iv(self.program, self.location, value.len, value.ptr", .{}),
                                        else => unreachable,
                                    }
                                },
                                u32 => {
                                    switch (vector.dimensions) {
                                        2 => std.log.debug("glProgramUniform2uiv(self.program, self.location, value.len, value.ptr", .{}),
                                        3 => std.log.debug("glProgramUniform3uiv(self.program, self.location, value.len, value.ptr", .{}),
                                        4 => std.log.debug("glProgramUniform4uiv(self.program, self.location, value.len, value.ptr", .{}),
                                        else => unreachable,
                                    }
                                },
                                f32 => {
                                    switch (vector.dimensions) {
                                        2 => std.log.debug("glProgramUniform2fv(self.program, self.location, value.len, value.ptr", .{}),
                                        3 => std.log.debug("glProgramUniform3fv(self.program, self.location, value.len, value.ptr", .{}),
                                        4 => std.log.debug("glProgramUniform4fv(self.program, self.location, value.len, value.ptr", .{}),
                                        else => unreachable,
                                    }
                                },
                                else => unreachable,
                            }
                        },
                        .matrix => |matrix| {
                            const transpose = false;
                            switch (matrix.row_count) { // we dont need to worry about col_count because we know its square
                                2 => std.log.debug("glProgramUniformMatrix2fv(self.program, self.location, value.len, transpose, @ptrCast(?* const c_float, value.ptr))", .{}),
                                3 => std.log.debug("glProgramUniformMatrix3fv(self.program, self.location, value.len, transpose, @ptrCast(?* const c_float, value.ptr))", .{}),
                                4 => std.log.debug("glProgramUniformMatrix4fv(self.program, self.location, value.len, transpose, @ptrCast(?* const c_float, value.ptr))", .{}),
                                else => unreachable,
                            }
                        },
                    }
                }

            }
        };

    };
}

pub fn initUniforms(program_handle : c_uint, comptime Uniforms : type) Uniforms {
    var uniforms : Uniforms = undefined;
    switch (@typeInfo(Uniforms)) {
        .Struct => |Struct| {
            inline for (Struct.fields) |field| {
                const name = field.name;
                _ = uniformInfo(field.field_type);  // make sure this is in fact a valid Uniform() type
                @field(uniforms, name) = .{
                    .program = program_handle,
                    .location = 0,
                };
                std.log.debug("glGetUniformLocation({d}, \"{s}\")", .{program_handle, name});
            }
            return uniforms;
        },
        else => @compileError("uniforms type must be a struct, not " ++ @typeName(Uniforms)),
    }
}

pub const UniformInfo = struct {
    Element : type,
    element_info : ElementInfo,

    pub const ElementInfo = struct {
        Primitive : type,
        kind : Kind,

        pub const SingleKind = union(enum) {
            primitive : type, 
            vector : math.meta.VectorTypeInfo,
            matrix : math.meta.MatrixTypeInfo,

            pub fn getPrimitiveType(comptime self : @This()) type {
                return switch (self) {
                    .primitive => |primitive| primitive,
                    .vector => |vector| vector.Element,
                    .matrix => |matrix| matrix.Element,
                };
            }

        };

        pub const Kind = union(enum) {
            single : SingleKind,
            array : ArrayKind,

            pub fn getPrimitiveType(comptime self : @This()) type {
                return switch (self) {
                    .single => |single| single.getPrimitiveType(),
                    .array => |array| array.getPrimitiveType(),
                };
            }

        };

        pub const ArrayKind = struct {
            element_kind : SingleKind,
            length : usize,
            Child : type,

            pub fn getPrimitiveType(comptime self : @This()) type {
                return self.element_kind.getPrimitiveType();
            }
        };

        fn getKind(comptime E : type) Kind {
            switch (@typeInfo(E)) {
                .Int, .Float => return .{.single = .{.primitive = E}},
                .Array => |Array| {
                    const element_kind = getKind(Array.child);
                    switch (element_kind) {
                        .single => |single| return .{
                            .array = .{
                                .element_kind = single,
                                .length = Array.len,
                                .Child = Array.child,
                            }
                        },
                        .array => @compileError("only single-dimensional arrays are supported for uniforms, not " ++ @typeName(E)),
                    }
                },
                .Struct => |Struct| {
                    if (Struct.layout != .Extern) {
                        @compileError("only extern structs allowed for uniforms. cannot use " ++ @typeName(E));
                    }
                    const vectorInfo = math.meta.vectorTypeInfo(E).option();
                    const matrixInfo = math.meta.matrixTypeInfo(E).option();
                    if (matrixInfo) |info| {
                        return .{
                            .single = .{
                                .matrix = info,
                            }
                        };
                    }
                    if (vectorInfo) |info| {
                        return .{
                            .single = .{
                                .vector = info,
                            }
                        };
                    }
                    @compileError("only vector and matrix structs are supported for uniforms currently. invalid struct type " ++ @typeName(E));
                },
                else => @compileError("unsupported uniform element type " ++ @typeName(E)),
            }
        }

        pub fn from(comptime E : type) ElementInfo {
            const kind = getKind(E);
            return .{
                .Primitive = kind.getPrimitiveType(),
                .kind = kind,
            };
        }

    };
};

pub fn uniformInfo(comptime U : type) UniformInfo {
    if (@hasDecl(U, "Element") and @hasField(U, "location")) {
        const Element = U.Element;
        var info : UniformInfo = undefined;
        info.Element = Element;
        info.element_info = UniformInfo.ElementInfo.from(Element);
        switch (info.element_info.Primitive) {
            i32, u32, f32 => {},
            else => |P| @compileError("uniform must have primitive type i32, u32, or f32, not " ++ @typeName(P) ++ " (for uniform type " ++ @typeName(U) ++ ")"),
        }
        const single = switch (info.element_info.kind) {
            .single => |s| s,
            .array => |array| array.element_kind,
        };
        switch (single) {
            .primitive => {},
            .vector => |vector| {
                if (vector.dimensions < 2 or vector.dimensions > 4) {
                    @compileError("vector uniforms but have 2, 3, or 4 dimensions, unlike " ++ @typeName(Element));
                }
            },
            .matrix => |matrix| {
                if (matrix.row_count != matrix.col_count) {
                    @compileError("non-square matrix uniforms are currently unsupported: " ++ @typeName(Element));
                }
                const d = matrix.row_count;
                if (d < 2 or d > 4) {
                    @compileError("matrix uniforms but have 2, 3, or 4 dimensions, unlike " ++ @typeName(Element));
                }
                if (matrix.Element != f32) {
                    @compileError("only f32 matrix uniforms supportedm unlike " ++ @typeName(Element));
                }
            },
        }
        return info;
    }
    else {
        @compileError("must provide Uniform(T) type, not " ++ @typeName(U));
    }
}

fn logKindInfo(comptime kind_type : [] const u8, comptime single : UniformInfo.ElementInfo.SingleKind) void {
    switch (single) {
        .primitive => |primitive| {
            std.log.debug("element_info.kind.{s}.primitive: {}", .{kind_type, @typeName(primitive)});
        },
        .vector => |vector| {
            std.log.debug("element_info.kind.{s}.vector.Element: {}", .{kind_type, @typeName(vector.Element)});
            std.log.debug("element_info.kind.{s}.vector.dimensions: {d}", .{kind_type, vector.dimensions});
        },
        .matrix => |matrix| {
            std.log.debug("element_info.kind.{s}.matrix.Element: {}", .{kind_type, @typeName(matrix.Element)});
            std.log.debug("element_info.kind.{s}.matrix.row_count: {d}", .{kind_type, matrix.row_count});
            std.log.debug("element_info.kind.{s}.matrix.col_count: {d}", .{kind_type, matrix.row_count});
        },
    }
}

fn logInfo(comptime U : type) void {
    const info = uniformInfo(U);
    const ei = info.element_info;
    std.log.debug("uniform: {}", .{@typeName(U)});
    std.log.debug("info.Element: {}", .{@typeName(info.Element)});
    std.log.debug("element_info.Primitive: {}", .{@typeName(ei.Primitive)});
    switch (ei.kind) {
        .single => |single| {
            logKindInfo("single", single);
        },
        .array => |array| {
            logKindInfo("array.element_kind", array.element_kind);
            std.log.debug("element_info.kind.array.length: {d}", .{array.length});
        },
    }
}

test "uniform infos" {
    std.testing.log_level = .debug;
    logInfo(Uniform(f32));
    logInfo(Uniform([32]f32));
    logInfo(Uniform(math.glm.Vec3));
    logInfo(Uniform([128]math.glm.Vec2));
    logInfo(Uniform(math.glm.Mat2));
    logInfo(Uniform([16]math.glm.Mat4));
}

test "uniform set" {
    std.testing.log_level = .debug;
    (Uniform(f32){}).set(4);
    (Uniform(math.glm.Vec3){}).set(math.glm.Vec3.zero);
    (Uniform(math.glm.Mat4){}).set(math.glm.Mat4.identity);
    (Uniform([18]f32){}).set(&[3]f32{1, 2, 3});
}

test "init uniforms" {
    std.testing.log_level = .debug;
    const Uniforms = struct {
        model_mat : Uniform(math.glm.Mat4),
        view_mat : Uniform(math.glm.Mat4),
        proj_mat : Uniform(math.glm.Mat4),
        color : Uniform(math.color.ColorF32),
        lookup : Uniform([32]f32),
    };
    _ = initUniforms(32, Uniforms);

}